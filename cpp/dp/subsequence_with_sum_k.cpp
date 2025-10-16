#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &temp) {
  for (auto i : temp) {
    cout << i << " ";
  }
  cout << endl;
}

void f(int idx, int sum, int target, vector<int> &temp, vector<int> &nums) {
  if (idx >= nums.size() || sum > target) {
    return;
  }

  if (sum == target) {
    print(temp);
    return;
  }

  temp.push_back(nums[idx]);
  f(idx + 1, sum + nums[idx], target, temp, nums);
  temp.pop_back();
  f(idx + 1, sum, target, temp, nums);
}

void subsequence_with_sum_k(vector<int> &nums, int target) {
  vector<int> temp;
  f(0, 0, target, temp, nums);
}

int main() {
  int N = 0, target = 0;
  cin >> N >> target;

  vector<int> arr;
  while (N--) {
    int temp = 0;
    cin >> temp;
    arr.push_back(temp);
  }

  subsequence_with_sum_k(arr, target);
}
