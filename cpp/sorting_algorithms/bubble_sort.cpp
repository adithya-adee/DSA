#include "sorting.hpp"
#include <utility>

namespace sorting_algo {

/*
 Bubble Sort Algorithm
 Time Complexity - O(N^2)
 Space Complexity - O(1)
 INTUTION : Just pick the larger number and keep on swapping till it reaches the
 end
 ANALOGY : Bubble rising the water surface
*/
void bubble_sort(std::vector<int> &nums) {
    if (nums.empty()) {
        return;
    }
    bool swapped = false;
    for (size_t i = 0; i < nums.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < nums.size() - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

} // namespace sorting_algo
