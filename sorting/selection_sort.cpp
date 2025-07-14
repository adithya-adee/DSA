// Select the minimum element and place it to the front.
// i.e selecting min element and replacing it with front
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void selection_sort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int min_idx = i;
      for (int j = i; j < n; j++) {
        if (nums[j] < nums[min_idx]) {
          min_idx = j;
        }
      }

      swap(nums[i], nums[min_idx]);
    }
  }
};
