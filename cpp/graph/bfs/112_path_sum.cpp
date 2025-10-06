#include <queue>
#include <type_traits>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool hasPathSumRecur(TreeNode *root, int currSum, int targetSum) {
    if (!root) {
      return false;
    }

    currSum += root->val;

    if (!root->left && !root->right) {
      return currSum == targetSum;
    }

    return hasPathSumRecur(root->left, currSum, targetSum) ||
           hasPathSumRecur(root->right, currSum, targetSum);
  }

  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return false;
    }

    return hasPathSumRecur(root, 0, targetSum);
  }
};
