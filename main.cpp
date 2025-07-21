#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {}
};

int main() {
  Solution s1;

  vector<int> nums = {1, 2, 3};
  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums.size(); j++) {
      for (int k = 0; k < nums.size(); k++) {
        cout << k << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
