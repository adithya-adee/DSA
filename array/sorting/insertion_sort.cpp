// Insertion sort is a simple sorting algorithm that works by iteratively
// inserting each element of an unsorted list into its correct position in a
// sorted portion of the list. It is like sorting playing cards in your hands.
// You split the cards into two groups: the sorted cards and the unsorted cards

#include <vector>
using namespace std;

class Solution {
  void insertion_sort(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int key = nums[i];
      int j = i - 1;

      while (j >= 0 && nums[j] > key) {
        nums[j + 1] = nums[j];
        j = j - 1;
      }

      nums[j + 1] = key;
    }
  }
};
