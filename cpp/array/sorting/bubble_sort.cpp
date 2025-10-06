// Its like bubbles coming up to the surface.
// Bubble Sort is the simplest sorting algorithm that works by repeatedly
// swapping the adjacent elements if they are in the wrong order. This algorithm
// is not suitable for large data sets as its average and worst-case time
// complexity are quite high.

#include <utility>
#include <vector>
using namespace std;

class Solution {
  void bubble_sort(vector<int> &nums) {
    int n = nums.size();
    bool swapped = false;

    for (int i{}; i < n; i++) {
      swapped = false;
      for (int j = 0; j < n - i - 1; j++) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[i], nums[j]);
          swapped = true;
        }
      }
      if (!swapped)
        break;
    }
  }
};
