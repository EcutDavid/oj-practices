/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function(equations, values, queries) {
  const adj = new Map();
  equations.forEach((e, i) => {
    for (let j = 0; j < 2; j++) {
      if (!!adj.get(e[j])) continue;
      adj.set(e[j], new Map());
    }
    adj.get(e[0]).set(e[1], 1 / values[i]);
    adj.get(e[1]).set(e[0], values[i]);
  });

  const ret = [];
  queries.forEach(q => {
    if (!adj.get(q[0]) || !adj.get(q[1])) {
      ret.push(-1);
      return;
    }
    if (q[0] == q[1]) {
      ret.push(1);
      return;
    }
    ret.push(bfs(adj, q[1], q[0]));
  });
  return ret;
};

function bfs(adj, start, end) {
  const visited = new Set();
  let ret = -1;

  const walk = (node, cur) => {
    if (visited.has(node)) return;
    visited.add(node);
    if (ret != -1) return;
    if (node == end) {
      ret = cur;
      return;
    }
    for (const d of adj.get(node)) {
      walk(d[0], cur * d[1]);
    }
  };
  walk(start, 1);

  return ret;
}
