#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  void bfs(int i, int j, vector<vector<bool>> &visited,
           vector<vector<int>> &mat, vector<vector<int>> &result) {

    int n = mat.size(), m = mat[0].size();
    queue<pair<int, int>> q;
    visited[i][j] = 1;
    q.push({i, j});

    vector<int> dRow = {1, 0, -1, 0};
    vector<int> dCol = {0, 1, 0, -1};

    int distance = 1;
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;

      bool foundZ = false;
      for (int i = 0; i < 4; i++) {
        int nRow = x + dRow[i];
        int nCol = y + dCol[i];

        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
          if (mat[nRow][nCol] == 0)
            foundZ = true;
          else
            q.push({nRow, nCol});
        }
      }
      if (!foundZ) {
        distance++;
      }
    }
    result[i][j] = distance;
  }

  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> result(n, vector<int>(m, 0));
    queue<int> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] != 0) {
          bfs(i, j, visited, mat, result);
        }
      }
    }

    return result;
  }
};

int main() {
  Solution sol;

  // Example Input
  vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

  cout << "Original Matrix:" << endl;
  for (const auto &row : mat) {
    for (int cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }

  vector<vector<int>> result = sol.updateMatrix(mat);

  cout << "Result Matrix : " << endl;
  for (const auto &row : result) {
    for (int cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }

  return 0;
}
