#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print(vector<T> arr) {
  for (const auto &i : arr) {
    cout << i << " ";
  }

  cout << endl;
}

void merge(int low, int mid, int high, vector<int> &arr) {
  vector<int> temp;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }

  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i < high; i++) {
    arr[i] = temp[i - low];
  }
}

void merge_sort(int left, int right, vector<int> &arr) {
  if (left >= right)
    return;

  int mid = (right + left) / 2;

  merge_sort(left, mid, arr);
  merge_sort(mid + 1, right, arr);
  merge(left, mid, right, arr);
}

int main() {
  int N;
  cin >> N;

  vector<int> arr(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  print(arr);

  merge_sort(0, arr.size() - 1, arr);

  print(arr);
}
