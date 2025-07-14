#include <stack>
using namespace std;

class MinStack {
public:
  stack<int> st;
  stack<int> minSt;
  MinStack() {}

  void push(int val) {
    st.push(val);

    if (!minSt.empty()) {
      int minVal = min(st.top(), minSt.top());

      minSt.push(minVal);
    } else {
      minSt.push(val);
    }
  }

  void pop() {
    st.pop();
    minSt.pop();
  }

  int top() { return st.top(); }

  int getMin() { return minSt.top(); }
};
