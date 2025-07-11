
#include "tree_node.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }
    return checkBalance(root) != -1;
  }

private:
  int checkBalance(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1) {
      return -1;
    }
    int rightHeight = checkBalance(root->right);

    if (rightHeight == -1) {
      return -1;
    }
    if (abs(leftHeight - rightHeight) > 1) {
      return -1;
    }

    return 1 + max(leftHeight, rightHeight);
  }
};

int main() {

  TreeNode s1(1);
  s1.left = new TreeNode(9);
  s1.right = new TreeNode(20);

  s1.right->right = new TreeNode(7);
  s1.right->left = new TreeNode(15);

  Solution s2;
  cout << s2.isBalanced(&s1);
  return 0;
}
