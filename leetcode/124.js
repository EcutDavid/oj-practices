function calcMaxSum(root, ret) {
  if (!root.left && !root.right) {
    ret.val = Math.max(ret.val, root.val);
    return root.val;
  }

  let best = root.val;
  const choices = [best];
  [root.left, root.right].forEach(n => {
    const subMax = n ? calcMaxSum(n, ret) : 0;
    best += subMax > 0 ? subMax : 0;
    if (n) choices.push(choices[0] + subMax);
  });

  ret.val = Math.max(ret.val, best);
  return Math.max(...choices);
}

var maxPathSum = function(root) {
  const ret = { val: -1e20 };
  calcMaxSum(root, ret);
  return ret.val;
};
