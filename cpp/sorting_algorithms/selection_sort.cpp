#include <vector>

namespace sorting_algo {
// Selection Sort Algorithm
// Time Complexity - O(N^2)
// Space Complexity - O(1)
// INTUTION : Select the minimum element from the list and place it at the
// beginning
void selection_sort(std::vector<int> &nums) {
    for (size_t i = 0; i < nums.size(); i++) {
        int min = i;
        for (size_t j = i; j < nums.size(); j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        std::swap(nums[i], nums[min]);
    }
}
} // namespace sorting_algo
