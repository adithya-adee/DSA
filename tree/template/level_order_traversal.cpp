#include "binary_tree.h"
#include <iostream>
#include <queue>

using namespace std;

template <typename T> void Node<T>::level_order(Node *root) {

  if (!root) {
    cout << "Root is null" << endl;
    return;
  }
  queue<Node *> q;

  q.push(root);
  while (!q.empty()) {
    Node *current = q.front();
    if (current->left) {
      q.push(current->left);
    }
    if (current->right) {
      q.push(current->right);
    }

    cout << current->val << " ";
    q.pop();
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

  return 0;
}
