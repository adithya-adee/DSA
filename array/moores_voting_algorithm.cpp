#include <bits/stdc++.h>
using namespace std;

int majoritymajorEleement(vector<int> v) {

  // size of the given array:
  int n = v.size();
  int freqCnt{}, majorEle{};

  for (const int &num : v) {
    if (freqCnt == 0) {
      majorEle = num;
    }
    if (num != majorEle)
      freqCnt--;
    else
      freqCnt++;
  }

  // checking if the stored majorEleement
  //  is the majority majorEleement:
  int freqCnt1 = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == majorEle)
      freqCnt1++;
  }

  if (freqCnt1 > (n / 2))
    return majorEle;
  return -1;
}

int main() {
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majoritymajorEleement(arr);
  cout << "The majority majorEleement is: " << ans << endl;
  return 0;
}
