#include "print_template.hpp"
#include "sorting_algorithms/sorting.hpp"
#include <vector>
int main() {
    std::vector<int> nums = {3, 1, 4, 5, 2, 8, 9};
    // sorting_algo::bubble_sort(nums);
    // sorting_algo::insertion_sort(nums);
    sorting_algo::selection_sort(nums);
    // sorting_algo::merge_sort(0, nums.size() - 1, nums);
    // sorting_algo::quick_sort(0, nums.size() - 1, nums);
    print_custom::print_vec(nums);
}
