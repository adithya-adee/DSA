#include "tree_node.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
  int diameter;

  int calculateHeight(TreeNode *root) {

    if (!root)
      return 0;

    int lh = calculateHeight(root->left);
    int rh = calculateHeight(root->right);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
  }

  int diameterOfBinaryTree(TreeNode *root) {
    calculateHeight(root);

    return diameter;
  }
};
int main() {

  TreeNode s1(1);
  s1.left = new TreeNode(9);
  s1.right = new TreeNode(20);

  s1.right->right = new TreeNode(7);
  s1.right->left = new TreeNode(15);

  Solution s2;
  cout << s2.diameterOfBinaryTree(&s1);
  return 0;
}
