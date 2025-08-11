#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  int maxLen(vector<int> &nums) {
    unordered_map<int, int> mpp;
    int maxCnt{}, sum{};
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum == 0) {
        maxCnt = i + 1;
      } else {
        if (mpp.find(sum) != mpp.end()) {
          maxCnt = max(maxCnt, i - mpp[sum]);
        } else {
          mpp[sum] = i;
        }
      }
    }

    return maxCnt;
  }
};
