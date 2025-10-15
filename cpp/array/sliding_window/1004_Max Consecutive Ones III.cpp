#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int len = nums.size(), left = 0, max_length = INT_MIN;

    for (int right = 0; right < len; right++) {
      if (nums[right] == 0)
        k--;

      while (k == -1) {
        if (nums[left] == 0)
          k++;
        left++;
      }

      max_length = max(max_length, right - left + 1);
    }

    return (max_length == INT_MAX) ? 0 : max_length;
  }
};
