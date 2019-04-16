/**
 * @param {number[]} T
 * @return {number[]}
 */
var dailyTemperatures = function(T) {
  const s = [];
  const ret = [];
  for (let i = T.length - 1; i >= 0; i--) {
    while (s.length && s[s.length - 1].val <= T[i]) {
      s.pop();
    }
    ret.push(s.length ? s[s.length - 1].index - i : 0);
    s.push({ val: T[i], index: i });
  }
  return ret.reverse();
};
