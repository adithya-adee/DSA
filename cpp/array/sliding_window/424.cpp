#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> window;

    int len = s.size(), max_length = 0, maxf = 0;
    for (int i = 0; i < len; i++) {
      maxf = max(maxf, ++window[s[i]]);

      if (max_length - maxf < k)
        max_length++;
      else
        window[s[i - max_length]]--;
    }

    return max_length;
  }
};
