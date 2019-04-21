/**
 * @param {number} R
 * @param {number} C
 * @param {number} r0
 * @param {number} c0
 * @return {number[][]}
 */
var allCellsDistOrder = function(R, C, r0, c0) {
  const ret = [];
  for (let i = 0; i < R; i++) {
    for (let j = 0; j < C; j++) {
      ret.push([i, j]);
    }
  }
  const getV = (i, j) => Math.abs(i - r0) + Math.abs(j - c0);
  ret.sort((a, b) => getV(a[0], a[1]) - getV(b[0], b[1]));
  return ret;
};
