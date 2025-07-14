#include <vector>

using namespace std;
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    int wp = 1;
    for (int rp = 1; rp < n; rp++) {
      if (nums[rp] != nums[wp - 1]) {
        nums[wp] = nums[rp];
        wp++;
      }
    }

    return wp;
  }
};
