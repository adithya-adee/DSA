#include <iostream>

using namespace std;

template <typename T> class Node {
public:
  Node *left;
  Node *right;
  T val;

  Node(int data) : val{data}, left{nullptr}, right{nullptr} {}

  void preorder(Node *root) {
    if (!root) {
      return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }

  void inorder(Node *root) {
    if (!root) {
      return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }

  void postorder(Node *root) {
    if (!root) {
      return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
  }

  void level_order(Node *root);
  int height(Node *root);
};
