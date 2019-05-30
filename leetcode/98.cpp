#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef int i32;
typedef pair<i32, i32> pi32;

class Solution {
 private:
  void processMemo(TreeNode* root, unordered_map<TreeNode*, pi32>& memo) {
    if (!root) return;
    i32 vMin = root->val;
    i32 vMax = root->val;

    vector<TreeNode*> children = {root->left, root->right};
    for (auto child : children) {
      if (!child) continue;
      if (memo.count(child) == 0) processMemo(child, memo);
      vMin = min(vMin, memo[child].first);
      vMax = max(vMax, memo[child].second);
    }

    memo[root] = {vMin, vMax};
  }

  bool validate(TreeNode* root, unordered_map<TreeNode*, pi32>& memo) {
    if (!root) return true;

    if (root->left && (memo[root->left].second >= root->val)) return false;
    if (root->right && (memo[root->right].first <= root->val)) return false;
    return validate(root->left, memo) && validate(root->right, memo);
  }

 public:
  bool isValidBST(TreeNode* root) {
    unordered_map<TreeNode*, pi32> memo;
    processMemo(root, memo);
    return validate(root, memo);
  }
};