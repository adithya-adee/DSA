#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    for (size_t i{}, j{s.size() - 1}; i < s.size() && i < j; i++, j--) {
      swap(s[i], s[j]);
    }
  }
};
