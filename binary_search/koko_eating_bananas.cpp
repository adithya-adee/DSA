
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    sort(piles.begin(), piles.end());

    int min_banana = piles[0], max_banana = piles[piles.size() - 1];

    int minK = max_banana;
    while (min_banana <= max_banana) {
      int mid = (min_banana + max_banana) / 2;

      int time_taken = calculate_time_taken(piles, mid);

      if (time_taken > h) {
        min_banana = mid + 1;
        minK = mid;
      } else {
        max_banana = mid - 1;
      }
    }

    return minK;

    return min_banana;
  }

private:
  int calculate_time_taken(vector<int> &piles, int k) {
    int hour = 0;
    cout << "banana " << k;
    for (int i = 0; i < piles.size(); i++) {

      if (k >= piles[i]) {
        hour++;
      } else {
        int ceilVal = (piles[i] / k) + ((piles[i] % k) != 0);
        hour = hour + ceilVal;
      }

      cout << "time_taken for " << piles[i] << "=> " << hour << endl;
    }
    return hour;
  }
};

int main() {

  vector<int> piles = {1, 4, 3, 2};
  int h = 9;

  Solution s1;
  cout << s1.minEatingSpeed(piles, h) << endl;

  return 0;
}
