#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {

    for(int i = 0;i< matrix.size(); i++) {
      int window = matrix[i].size() - 1;

        cout << matrix[i][0] << matrix[i] [window] << endl;
      if(matrix[i][0] > target && matrix[i][window] < target) {
        continue; 
      }
      else {
        cout << "ELSE" << endl;
        int left = 0, right = matrix[i].size() -1 ;

        while (left <= right) {
          int mid = (left + right) / 2;

          if(matrix[i][mid] == target) {
            return true;
          }else if (matrix[i][mid] > target) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        }
      }
    } 

    return false;
  }
};

int main() {

  vector<vector<int>> matrix={{1,3,5,7},{10,11,13,20},{23,30,34,60}};
  int target=13;
  Solution s1;
  cout <<  s1.searchMatrix(matrix, target);
  return 0;
}
