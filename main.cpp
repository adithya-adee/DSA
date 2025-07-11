#include "tree/tree_node.hpp"
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    vector<TreeNode *> p1;
    inorder(p, p1);

    vector<TreeNode *> q1;
    inorder(q, q1);

    if (p1.size() != q1.size())
      return false;

    for (int i = 0; i < p1.size(); i++) {
      if (p1[i]->val != q1[i]->val) {
        return false;
      }
    }
    return true;
  }

  void inorder(TreeNode *root, vector<TreeNode *> &store) {
    if (!root)
      return;
    inorder(root->left, store);
    store.push_back(root);
    inorder(root->right, store);
  }
};

int main() {

  TreeNode s1(1);
  s1.left = new TreeNode(2);
  TreeNode s2(1);
  s2.left = new TreeNode(2);

  Solution s3;
  cout << s3.isSameTree(&s1, &s2);

  return 0;
}
