#include <algorithm>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    reverse(s.begin(), s.end());
    map<char, int> rti = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                          {'C', 100}, {'D', 500}, {'M', 1000}};
    int res{};
    res += rti[s[0]];
    for (int i = 1; i < s.size(); i++) {
      if (rti[s[i]] < rti[s[i - 1]]) {
        res -= rti[s[i]];
      } else {
        res += rti[s[i]];
      }
    }

    return res;
  }
};
