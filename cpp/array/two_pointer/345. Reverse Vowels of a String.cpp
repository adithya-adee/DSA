#include <bits/stdc++.h>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    unordered_set<char> vowelSet{'a', 'e', 'i', 'o', 'u',
                                 'A', 'E', 'I', 'O', 'U'};
    size_t i{}, j{s.size() - 1};

    while (i < j) {
      while (i < j && vowelSet.find(s[i]) == vowelSet.end()) {
        i++;
      }
      while (i < j && vowelSet.find(s[j]) == vowelSet.end()) {
        j--;
      }

      if (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
      }
    }

    return s;
  }
};
