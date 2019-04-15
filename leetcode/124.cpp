#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getSum(TreeNode* root, int& bestPathSum) {
  if (!root->left && !root->right) {
    bestPathSum = max(bestPathSum, root->val);
    return root->val;
  }

  int bestPath = root->val;
  int bestSub = root->val;
  int left = root->left ? getSum(root->left, bestPathSum) : 0;
  bestPath += left > 0 ? left : 0;
  int right = root->right ? getSum(root->right, bestPathSum) : 0;
  bestPath += right > 0 ? right : 0;
  bestPathSum = max(bestPathSum, bestPath);

  if (left < right) swap(left, right);
  bestSub = max(bestSub, bestSub + left);
  return bestSub;
}

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int ret = int(-1e9);
    getSum(root, ret);
    return ret;
  }
};