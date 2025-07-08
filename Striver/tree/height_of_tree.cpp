#include "binary_tree.h"
#include <iostream>
#include <stack>

using namespace std;

template <typename T> int Node<T>::height(Node *root) {
  if (!root) {
    cout << "No root found" << endl;
    return 0;
  }

  stack<Node *> st;
  st.push(root);

  int max_h = 0, h = 0;
  while (!st.empty()) {
  }
}
