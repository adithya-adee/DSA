
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    int freshCount{};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({{i, j}, 0});
          visited[i][j] = 2;
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
            visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
          visited[nrow][ncol] = 2;
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
