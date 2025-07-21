#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    vector<string> words;
    string word = "";
    for (char &c : s) {
      if (c == ' ') {
        if (word != "") {
          words.push_back(word);
          word = "";
        }
      } else {
        word.push_back(c);
      }
    }
    if (word != "")
      words.push_back(word);

    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
      result.append(words[i]);
      if (i != 0)
        result.push_back(' ');
    }

    return result;
  }
};
