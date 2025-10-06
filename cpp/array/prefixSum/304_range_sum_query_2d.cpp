#include <vector>
using namespace std;

class NumMatrix {
public:
  vector<vector<int>> prefixSum;
  NumMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    prefixSum.resize(n, vector<int>(m));
    int sum{};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum += matrix[i][j];
        prefixSum[i][j] = sum;
      }
      sum = 0;
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0, m = prefixSum[0].size();
    for (int i = row1; i <= row2; i++) {
      for (int j = 0; j < col2; j++) {
        if (j < col1 && j > col2) {
          sum -= prefixSum[i][j];
        } else if (j == col2) {
          sum += prefixSum[i][j];
        }
      }
    }
    return sum;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
