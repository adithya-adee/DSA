
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      int mid = (left + right) / 2;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }
};

int main() {

  Solution s1;
  vector<int> nums = {1, 2, 3, 4, 5, 6};

  cout << s1.search(nums, 2) << endl;
}
