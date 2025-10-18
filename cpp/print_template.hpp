#ifndef PRINT_TEMPLATE
#define PRINT_TEMPLATE

#include <iostream>
#include <vector>

namespace print_custom {

// Template for printing vector
template <typename T> void print_vec(const std::vector<T> &vec) {
    for (const auto &v : vec) {
        std::cout << v << " ";
    }
    std::cout << "\n\n\n";
}

} // namespace print_custom
#endif // !PRINT_TEMPLATE
#define PRINT_TEMPLATE
