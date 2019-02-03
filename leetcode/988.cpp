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

void t(TreeNode *root, string rep, vector<string> &v) {
  rep = rep + (char)('a' + root->val);
  if (root->left != NULL) t(root->left, rep, v);
  if (root->right != NULL) t(root->right, rep, v);
  if (root->left == NULL && root->right == NULL) v.PB(string(rep.rbegin(), rep.rend()));
}

class Solution {
 public:
  string smallestFromLeaf(TreeNode *root) {
    string rep = "";
    vector<string> v;
    t(root, rep, v);
    sort(all(v));
    return v[0];
  }
};