#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int orangeRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    int freshCount = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({{i, j}, 0});
          visited[i][j] = 2;
        } else {
          visited[i][j] = 0;
        }

        if (grid[i][j] == 1) {
          freshCount++;
        }
      }
    }

    int tm{}, cnt{};

    vector<int> drow = {-1, 0, +1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    while (!q.empty()) {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int t = q.front().second;
      tm = max(t, tm);
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            visited[row][col] != 2 && grid[row][col] == 1) {
          visited[row][col] = 2;
          q.push({{nrow, ncol}, t + 1});
          cnt++;
        }
      }
    }

    if (cnt != freshCount) {
      return -1;
    }

    return tm;
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
