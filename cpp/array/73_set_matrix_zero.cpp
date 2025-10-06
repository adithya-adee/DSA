
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<pair<int, int>> coordinates;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          coordinates.push_back({i, j});
        }
      }
    }

    for (int i = 0; i < coordinates.size(); i++) {
      pair<int, int> coor = coordinates[i];

      for (int e = 0; e < m; e++) {
        matrix[coor.first][e] = 0;
      }

      for (int e = 0; e < n; e++) {
        matrix[e][coor.second] = 0;
      }
    }
  }
};

int main() {
  Solution s1;
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  s1.setZeroes(matrix);

  for (auto &x : matrix) {
    for (auto &y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
  return 0;
}
