#include "print_template.hpp"
#include "sorting_algorithms/sorting.hpp"
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    insertion_sort(nums);
    print_temp(nums);
}
