#include "tree_node.hpp"
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    vector<int> sorted;
    inorder(root, sorted);

    for (int i = 0; i < sorted.size() - 1; i++) {
      if (sorted[i] > sorted[i + 1]) {
        return false;
      }
    }

    return true;
  }

  void inorder(TreeNode *root, vector<int> &sorted) {
    if (!root) {
      return;
    }

    inorder(root->left, sorted);
    sorted.push_back(root->val);
    inorder(root->right, sorted);
  }
};
