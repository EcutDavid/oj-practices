var mincostTickets = function(days, costs) {
  days.sort((a, b) => a - b);
  const memo = [0];
  days.forEach((day, i) => {
    const prev = i === 0 ? 0 : days[i - 1];
    for (let i = prev + 1; i < day; i++) {
      memo.push(memo[prev]);
    }
    const c1 = memo[day - 1] + costs[0];
    const c2 = memo[Math.max(day - 7, 0)] + costs[1];
    const c3 = memo[Math.max(day - 30, 0)] + costs[2];
    const best = Math.min(c1, c2, c3);
    memo.push(best);
  });
  return memo[memo.length - 1];
};
