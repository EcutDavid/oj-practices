#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void t(TreeNode *root, i32 x, i32 y, map<i32, vector<pi32>> &s) {
  if (root == NULL) return;
  s[x].PB({y, root->val});
  t(root->left, x - 1, y + 1, s);
  t(root->right, x + 1, y + 1, s);
}

class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<i32, vector<pi32>> s;
    vector<vector<i32>> ret;

    t(root, 0, 0, s);

    for (auto x : s) {
      sort(all(x.second));
      vi32 line;
      TR(x.second, it) {
        line.PB(it->second);
      }
      ret.PB(line);
    }
    return ret;
  }
};