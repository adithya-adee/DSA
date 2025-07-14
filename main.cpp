#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int m = image.size();
    int n = image[0].size();
    int val = image[sr][sc];

    vector<int> dRow = {1, 0, -1, 0};
    vector<int> dCol = {0, 1, 0, -1};

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    q.push({sr, sc});
    visited[sr][sc] = true;

    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];

        if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
            !visited[nRow][nCol] && image[nRow][nCol] == val) {
          image[nRow][nCol] = color;
          q.push({nRow, nCol});
        }
      }
    }

    return image;
  }
};

int main() {
  Solution s1;
  // Example 1: A graph with 2 provinces: {0, 1} and {2}
  vector<vector<int>> graph1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  cout << "--- Example 1 ---" << endl;
  int provinces1 = s1.findCircleNum(graph1);
  cout << "\nTotal number of provinces: " << provinces1 << endl;
  cout << "-------------------" << endl << endl;

  // Example 2: A graph with 1 province: {0, 1, 2, 3}
  vector<vector<int>> graph2 = {
      {1, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 1, 1}, {0, 0, 1, 1}};
  cout << "--- Example 2 ---" << endl;
  int provinces2 = s1.findCircleNum(graph2);
  cout << "\nTotal number of provinces: " << provinces2 << endl;
  cout << "-------------------" << endl;

  return 0;
}
