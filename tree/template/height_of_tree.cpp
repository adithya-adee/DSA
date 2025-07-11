#include "binary_tree.h"
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T> int Node<T>::height(Node *root) {
  int maxHeight = 0;
  calculate_tree_height(root, 0, &maxHeight);
  return maxHeight;
}

template <typename T>
void calculate_tree_height(Node<T> *root, int currentHeight, int *maxHeight) {
  if (!root) {
    return;
  }

  if (!root->right && !root->left) {
    cout << *maxHeight << endl;
    *maxHeight = max(*maxHeight, currentHeight);
  }

  if (root->left) {
    calculate_tree_height(root->left, currentHeight + 1, maxHeight);
  }
  if (root->right) {
    calculate_tree_height(root->right, currentHeight + 1, maxHeight);
  }
}

int main() {

  Node<int> s1(1);
  s1.left = new Node<int>(2);
  s1.left->right = new Node<int>(5);
  s1.left->left = new Node<int>(4);
  s1.right = new Node<int>(3);

  s1.right->right = new Node<int>(7);
  s1.right->left = new Node<int>(6);

  s1.preorder(&s1);
  cout << endl;
  s1.inorder(&s1);
  cout << endl;
  s1.postorder(&s1);
  cout << endl;

  cout << s1.height(&s1) << endl;
  return 0;
}
