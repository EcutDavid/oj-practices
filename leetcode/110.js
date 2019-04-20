function getHeightAndBalance(node) {
  if (!node) return [true, -1];
  const retL = getHeightAndBalance(node.left);
  const retR = getHeightAndBalance(node.right);
  if (!retL[0] || !retR[0]) return [false, -1];
  if (Math.abs(retL[1] - retR[1]) > 1) return [false, -1];
  return [true, Math.max(retL[1], retR[1]) + 1];
}

var isBalanced = function(root) {
  return getHeightAndBalance(root)[0];
};
