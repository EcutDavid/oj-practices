var uniquePaths = function(m, n) {
  const memo = [];
  for (let i = 0; i < m; i++) memo.push([]);
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (i == 0 || j == 0) {
        memo[i][j] = 1;
        continue;
      }
      memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
    }
  }
  return memo[m - 1][n - 1];
};
