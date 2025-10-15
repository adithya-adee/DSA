#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

// Solution : Instead of making all permutations and storing it in a vector
// We use hashmap to store the frequency => like a permutation

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();

    unordered_map<char, int> mpp;
    for (char &s : s1) {
      mpp[s]++;
    }

    unordered_map<char, int> window;
    int left = 0;
    for (int right = 0; right < len2; right++) {
      window[s2[right]]++;

      if (right - left + 1 == len1) {
        if (window == mpp)
          return true;

        window[s2[left]]--;

        if (window[s2[left]] == 0) {
          window.erase(s2[left]);
        }

        left++;
      }
    }

    return false;
  }
};
