
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    unordered_map<int, int> mpp;

    for (const int &p : people) {
      mpp[p]++;
    }

    sort(people.begin(), people.end());

    int cnt{};
    for (size_t i{people.size() - 1}; i >= 0; i--) {
      if (people[i] == limit)
        cnt++;
      else if (people[i] < limit) {
        int target = limit - people[i];
        if (mpp[target] > 1) {
          cnt++;
          mpp[target]--;
        }
      }
    }

    return cnt;
  }
};
