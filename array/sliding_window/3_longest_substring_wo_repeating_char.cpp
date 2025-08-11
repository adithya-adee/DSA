#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> char_set;
    int left{}, cnt{};
    for (int right{}; right < s.size(); right++) {
      if (char_set.find(s[right]) != char_set.end()) {
        while (left < right && char_set.find(s[right]) != char_set.end()) {
          char_set.erase(s[left]);
          left++;
        }
      }
      char_set.insert(s[right]);
      cnt = max(cnt, right - left + 1);
    }

    return cnt;
  }
};
