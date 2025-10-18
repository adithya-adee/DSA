#include <utility>
#include <vector>

namespace sorting_algo {
// Quick Sort Algorithm
// Time Complexity - O(n log n)
// Space Complexity - O(1)
int find_partition_idx(int low, int high, std::vector<int> &nums) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            std::swap(nums[i], nums[j]);
        }
    }

    std::swap(nums[i + 1], nums[high]);

    return i + 1;
}

void quick_sort(int low, int high, std::vector<int> &nums) {
    if (low < high) {
        int partition_idx = find_partition_idx(low, high, nums);
        quick_sort(low, partition_idx - 1, nums);
        quick_sort(partition_idx + 1, high, nums);
    }
}
} // namespace sorting_algo
