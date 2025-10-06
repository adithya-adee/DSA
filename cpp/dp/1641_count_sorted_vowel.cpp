#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void fun(int idx, int &count, int n, vector<char> &ls, vector<char> &vowels) {
    if (ls.size() == n) {
      count++;
      return;
    }
    if (idx == vowels.size()) {
      return;
    }

    ls.push_back(vowels[idx]);
    fun(idx, count, n, ls, vowels);
    ls.pop_back();
    fun(idx + 1, count, n, ls, vowels);
  }
  int countVowelStrings(int n) {
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
    vector<char> empty_vec;
    int count{};
    fun(0, count, n, empty_vec, vowels);
    return count;
  }
};
