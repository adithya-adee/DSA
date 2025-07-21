#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
  bool isPalindrome(string s) {
    string str = "";
    for (char &c : s) {
      if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ||
          c >= '0' && c <= '9') {
        str.push_back(tolower(c));
      }
    }

    string cpy = str;
    reverse(cpy.begin(), cpy.end());

    return cpy == str;
  }
};
