function minDistance(a, b) {
  const memo = [];
  for (let i = 0; i <= b.length; i++) {
    memo[i] = [i];
    for (let j = 1; j <= a.length; j++) {
      if (i == 0) {
        memo[i][j] = j;
        continue;
      }
      let effort = memo[i - 1][j - 1] + 1;
      if (a[j - 1] == b[i - 1]) effort--;
      effort = Math.min(effort, memo[i - 1][j] + 1);
      effort = Math.min(effort, memo[i][j - 1] + 1);
      memo[i][j] = effort;
    }
  }
  return memo[b.length][a.length];
}
