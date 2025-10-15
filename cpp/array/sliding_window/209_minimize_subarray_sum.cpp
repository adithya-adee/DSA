#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int len = nums.size();
    int left = 0, sum = 0, min_length = INT_MAX;
    for (int right = 0; right < len; right++) {
      sum += nums[right];

      while (sum >= target) {
        if (sum == target) {
          min_length = min(right - left + 1, min_length);
        }
        sum -= nums[left];
        left++;
      }
    }
    return min_length == INT_MAX ? 0 : min_length;
  }
};
