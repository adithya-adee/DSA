#include <vector>

using namespace std;

// IN PLACE
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();

    for (int i = 1; i < nums.size(); i++) {
      nums[i] *= nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
      nums[i] = nums[i + 1];
    }

    return nums;
  }
};

// NOT IN PLACE
// class Solution {
// public:
//   vector<int> productExceptSelf(vector<int> &nums) {
//     int n = nums.size();
//     vector<int> prefix(n);
//     vector<int> suffix(n);
//
//     prefix[0] = 1;
//     suffix[n - 1] = 1;
//     for (int i = 1; i < n; i++) {
//       prefix[i] = prefix[i - 1] * nums[i - 1];
//     }
//
//     for (int i = n - 2; i >= 0; i--) {
//       suffix[i] = suffix[i + 1] * nums[i + 1];
//     }
//
//     for (int i = 0; i < n; i++) {
//       nums[i] = prefix[i] * suffix[i];
//     }
//
//     return nums;
//   }
// };
