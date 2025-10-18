#ifndef SORTING_HPP
#define SORTING_HPP

#include <utility>
#include <vector>

// Bubble Sort Algorithm
// Time Complexity - O(N^2)
// Space Complexity - O(1)
void bubble_sort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        bool is_sorted = true;
        for (int j = 0; j < nums.size() - i; j++) {
            if (nums[i] < nums[j]) {
                std::swap(nums[i], nums[j]);
                is_sorted = false;
            }
        }

        if (is_sorted)
            break;
    }
}

// Insertion Sort Algorithm
// Time Complexity - O(N^2)
// Space Complexity - O(1)
void insertion_sort(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        int key = nums[i];
        int j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }
}

// Selection Sort Algorithm
// Time Complexity - O(N^2)
// Space Complexity - O(1)
void selection_sort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        int min = nums[i];
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] < min) {
                min = nums[j];
            }
        }
        std::swap(nums[i], nums[min]);
    }
}

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

// Quick Sort Algorithm
// Time Complexity - O(n log n)
// Space Complexity - O(1)
int find_partition_idx(int low, int high, std::vector<int> &nums) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nums[j] <= nums[high]) {
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

#endif // !SORTING_HPP
#define SORTING_HPP
