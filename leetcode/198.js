// House Robber 1.
var rob = function(nums) {
  let m = [0, 0];
  for (const n of nums) {
    const newM = [Math.max(m[0], m[1]), n + m[0]];
    m = newM;
  }
  return Math.max(m[0], m[1]);
};
