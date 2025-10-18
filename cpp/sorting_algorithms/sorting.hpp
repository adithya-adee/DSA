#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>

namespace sorting_algo {

/* ------ NORMAL O(N^2) ------ */

// Bubble Sort Algorithm
// Time Complexity - O(N^2)
// Space Complexity - O(1)
void bubble_sort(std::vector<int> &nums);

// Insertion Sort Algorithm
// Time Complexity - O(N^2)
// Space Complexity - O(1)
void insertion_sort(std::vector<int> &nums);

// Selection Sort Algorithm
// Time Complexity - O(N^2)
// Space Complexity - O(1)
void selection_sort(std::vector<int> &nums);

/* ------ DIVIDE & CONQUER ------ */

// Merge Sort Algorithm
// Time Complexity - O(n log n)
// Space Complexity - O(n) - for temp vector
void merge_sort(int low, int high, std::vector<int> &nums);

// Quick Sort Algorithm
// Time Complexity - O(n log n)
// Space Complexity - O(1)
void quick_sort(int low, int high, std::vector<int> &nums);

} // namespace sorting_algo
#endif // !SORTING_HPP
