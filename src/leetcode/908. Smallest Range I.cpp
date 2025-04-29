#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestRangeI(vector<int> &nums, int k) {
    size_t length = nums.size();
    int minimum_score{INT_MAX};
    for (size_t i{}; i < length; i++) {
      int max_num{INT_MAX}, min_num{INT_MIN};
      int score{};
      for (size_t j{}; j < length; j++) {
        max_num = (max_num < nums[j]) ? nums[j] : max_num;
        min_num = (min_num > nums[j]) ? nums[j] : min_num;
        score = max_num - min_num;
      }
      minimum_score = (minimum_score > min_num) ? min_num : minimum_score;
    }
    return minimum_score;
  }
};

int main() {
  Solution s1;
  std::vector<int> arr = {1, 3, 6};
  cout << s1.smallestRangeI(arr, 3) << endl;

  return 0;
}
