/**
 * @param {number[][]} costs
 * @return {number}
 */
var twoCitySchedCost = function(costs) {
  const getV = c => Math.abs(c[0] - c[1]);
  costs.sort((a, b) => getV(b) - getV(a));

  const aSet = new Set();
  const bSet = new Set();
  for (let i = 0; i < costs.length; i++) {
    if (aSet.size == costs.length / 2) {
      bSet.add(i);
      continue;
    }
    if (bSet.size == costs.length / 2) {
      aSet.add(i);
      continue;
    }
    if (costs[i][0] > costs[i][1]) {
      bSet.add(i);
    } else {
      aSet.add(i);
    }
  }

  let sum = 0;
  for (const i of aSet) {
    sum += costs[i][0];
  }
  for (const i of bSet) {
    sum += costs[i][1];
  }
  return sum;
};
