/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

function modify(cur, prev) {
  if (prev) {
    prev.left = null;
    prev.right = cur;
  }
  const right = cur.right;
  if (cur.left) {
    cur = modify(cur.left, cur);
  }
  if (right) {
    cur = modify(right, cur);
  }
  return cur;
}

/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
  if (!root) return null;
  modify(root);
  return root;
};
