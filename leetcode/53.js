/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  let ret = 0;
  let sumAcc = 0;
  for (const num of nums) {
    sumAcc = Math.max(sumAcc + num, num, 0);
    ret = Math.max(ret, sumAcc);
  }
  return ret;
};
