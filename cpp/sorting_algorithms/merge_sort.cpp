#include <vector>

namespace sorting_algo {
// Merge Sort Algorithm
// Time Complexity - O(n log n)
// Space Complexity - O(n) - for temp vector
void merge(int low, int mid, int high, std::vector<int> &nums) {
    std::vector<int> temp;

    int left = low, right = mid + 1;
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

void merge_sort(int low, int high, std::vector<int> &nums) {
    if (low >= high)
        return;

    int mid = (high + low) / 2;

    merge_sort(low, mid, nums);
    merge_sort(mid + 1, high, nums);
    merge(low, mid, high, nums);
}
} // namespace sorting_algo
