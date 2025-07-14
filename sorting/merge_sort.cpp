#include <vector>
using namespace std;
class Solution {

private:
  void merge(vector<int> &nums, int left, int right, int mid) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
      L[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
      R[j] = nums[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into nums[left..right]
    while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
        nums[k] = L[i];
        i++;
      } else {
        nums[k] = R[j];
        j++;
      }
      k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
      nums[k] = L[i];
      i++;
      k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
      nums[k] = R[j];
      j++;
      k++;
    }
  }

public:
  void merge_sort(vector<int> &nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, right, mid);
  }
};
