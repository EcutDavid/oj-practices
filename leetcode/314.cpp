// Time cost: 24 mins
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  void parseRange(TreeNode* root, int& l, int& r, int cur) {
    if (!root) return;
    l = min(l, cur);
    r = max(r, cur);
    parseRange(root->left, l, r, cur - 1);
    parseRange(root->right, l, r, cur + 1);
  }

  // Inorder visit, does not work due to it's not layer by layer
  void visit(TreeNode* root, vector<vector<int>>& v, int cur, int l) {
    if (!root) return;
    v[cur - l].push_back(root->val);
    visit(root->left, v, cur - 1, l);
    visit(root->right, v, cur + 1, l);
  }

  void bfsVisit(TreeNode* root, vector<vector<int>>& v, int l) {
    if (!root) return;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      auto item = q.front();
      q.pop();
      v[item.second - l].push_back(item.first->val);
      if (item.first->left) q.push({item.first->left, item.second - 1});
      if (item.first->right) q.push({item.first->right, item.second + 1});
    }
  }

 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (!root) return ret;
    int l = 0;
    int r = 0;
    parseRange(root, l, r, 0);
    for (int i = l; i <= r; i++) {
      ret.push_back(vector<int>());
    }
    bfsVisit(root, ret, l);
    return ret;
  }
};