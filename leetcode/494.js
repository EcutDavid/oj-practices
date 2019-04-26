// Don't have to use recursion, iteration is much faster since
// all the operation can be represented by n that belongs to [0, 2^20).
function calc(level, nums, S, path, ret) {
  if (level === nums.length) {
    const sum = path.reduce((acc, d) => acc + nums[d] * 2, 0);
    if (sum === S) ret.count++;
    return;
  }
  path.push(level);
  calc(level + 1, nums, S, path, ret);
  path.pop();
  calc(level + 1, nums, S, path, ret);
}

/**
 * @param {number[]} nums
 * @param {number} S
 * @return {number}
 */
var findTargetSumWays = function(nums, S) {
  S = S - nums.reduce((acc, d) => acc - d, 0);
  const ret = { count: 0 };
  calc(0, nums, S, [], ret);
  return ret.count;
};
