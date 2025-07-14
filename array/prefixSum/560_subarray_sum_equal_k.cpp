#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    map<int, int> hashMap;
    int preSum{}, cnt{};
    hashMap.insert(0, 1);

    for (int num : nums) {
      if (hashMap[preSum - k]) {
        cnt += hashMap[preSum - k];
        hashMap[preSum] += 1;
      }
      preSum += num;
    }

    return cnt;
  }
};
