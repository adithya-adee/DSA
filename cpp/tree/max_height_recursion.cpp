#include "tree_node.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

int main() {

  TreeNode s1(1);
  s1.left = new TreeNode(2);
  s1.left->right = new TreeNode(5);
  s1.left->left = new TreeNode(4);
  s1.right = new TreeNode(3);

  s1.right->right = new TreeNode(7);
  s1.right->left = new TreeNode(6);

  Solution s2;
  cout << s2.maxDepth(&s1);
  return 0;
}
