
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    map<char, char> pairs = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    stack<char> st;

    for (const char &x : s) {
      if (pairs.count(x)) {
        st.push(pairs[x]);
      } else if (!st.empty() && st.top() == x) {
        st.pop();
      } else {
        return false;
      }
    }

    if (!st.empty())
      return false;
    else
      return true;
  }
};

int main() {

  Solution s1;
  string s = "({[]})";
  cout << s1.isValid(s) << endl;
}
