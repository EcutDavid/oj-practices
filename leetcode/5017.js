const M = 1e9 + 7;

function calc(path) {
  let ret = path[0];
  for (let i = 1; i < path.length; i++) {
    ret = (ret * 2 + path[i]) % M;
  }
  return ret;
}

function walk(node, path) {
  if (!node.left && !node.right) return calc(path.concat(node.val));

  let sum = 0;
  if (node.left) sum += walk(node.left, path.concat(node.val));
  if (node.right) sum += walk(node.right, path.concat(node.val));
  return sum % M;
}

var sumRootToLeaf = function(root) {
  if (!root) return 0;
  const ret = walk(root, []);
  return ret;
};
