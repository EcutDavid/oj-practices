/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(p) {
  let ret = 0;
  let prevMax = 0;
  for (let i = p.length - 1; i >= 0; i--) {
    ret = Math.max(ret, prevMax - p[i]);
    prevMax = Math.max(prevMax, p[i]);
  }
  return ret;
};
