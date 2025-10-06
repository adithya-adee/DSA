#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    return binary_search(nums, target, 0, nums.size() - 1);
  }

private:
  int binary_search(vector<int> &nums, int target, int left, int right) {
    if (left > right) {
      return -1;
    }

    int mid = (left + right) / 2;

    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      return binary_search(nums, target, left, mid - 1);
    } else {
      return binary_search(nums, target, mid + 1, right);
    }
  }
};

int main() {

  Solution s1;
  vector<int> nums = {-1, 0, 2, 4, 6, 8};
  int target = 4;

  cout << s1.search(nums, target) << endl;
}
