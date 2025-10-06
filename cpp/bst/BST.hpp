
#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "./tree_node.hpp"
#include <iostream>

class BinarySearchTree {
public:
  TreeNode *root;

  TreeNode *insert(TreeNode *node, int val) {
    if (!node)
      return new TreeNode(val);
    if (val > node->val)
      node->right = insert(node->right, val);
    else
      node->left = insert(node->left, val);
    return node;
  }

  TreeNode *search(TreeNode *node, int val) {
    if (!node || node->val == val)
      return node;
    return val > node->val ? search(node->right, val) : search(node->left, val);
  }

  TreeNode *inorderSuccessor(TreeNode *node) {
    while (node && node->left)
      node = node->left;
    return node;
  }

  TreeNode *deleteNode(TreeNode *node, int key) {
    if (!node)
      return nullptr;

    if (key < node->val) {
      node->left = deleteNode(node->left, key);
    } else if (key > node->val) {
      node->right = deleteNode(node->right, key);
    } else {
      if (!node->left && !node->right) {
        delete node;
        return nullptr;
      }
      if (!node->left) {
        TreeNode *temp = node->right;
        delete node;
        return temp;
      }
      if (!node->right) {
        TreeNode *temp = node->left;
        delete node;
        return temp;
      }

      TreeNode *temp = inorderSuccessor(node->right);
      node->val = temp->val;
      node->right = deleteNode(node->right, temp->val);
    }
    return node;
  }

  void inorder(TreeNode *node) {
    if (!node)
      return;
    inorder(node->left);
    std::cout << node->val << " ";
    inorder(node->right);
  }

public:
  BinarySearchTree() : root(nullptr) {}

  void insert(int val) { root = insert(root, val); }

  void deleteKey(int key) { root = deleteNode(root, key); }

  TreeNode *search(int val) { return search(root, val); }

  void printInOrder() {
    inorder(root);
    std::cout << std::endl;
  }

  TreeNode *getRoot() { return root; }
};

#endif // BINARY_SEARCH_TREE_HPP
