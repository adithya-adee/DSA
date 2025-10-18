#include <vector>

namespace sorting_algo {
/*
Insertion Sort Algorithm
Time Complexity - O(N^2)
Space Complexity - O(1)
INTUTION : Inserting new number into correct position when entering the subset
ANALOGY :  iteratively inserting each element of an unsorted list into its
correct position in a sorted portion of the list
*/

void insertion_sort(std::vector<int> &nums) {
    for (size_t i = 1; i < nums.size(); i++) {
        int key = nums[i];
        int j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }
}
} // namespace sorting_algo
