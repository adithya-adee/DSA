#include "tree_node.hpp"
#include <climits>
class Solution {
  bool check_valid(TreeNode *root, long long int min, long long int max) {
    if (!root) {
      return true;
    }

    if (root->val >= max || root->val <= min)
      return false;

    return check_valid(root->left, min, root->val) &&
           check_valid(root->right, root->val, max);
  }

public:
  bool isValidBST(TreeNode *root) {
    long long int min = LONG_LONG_MIN, max = LONG_LONG_MAX;
    return check_valid(root, min, max);
  }
};
