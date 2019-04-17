struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 private:
  TreeNode* last = nullptr;

 public:
  void flatten(TreeNode* root) {
    if (!root) return;
    if (last) {
      last->left = nullptr;
      last->right = root;
    }
    last = root;

    auto right = root->right;
    flatten(root->left);
    flatten(right);
  }
};
