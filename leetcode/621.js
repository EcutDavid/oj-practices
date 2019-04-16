const CHAR_CODE_A = "A".charCodeAt(0);
var leastInterval = function(tasks, n) {
  const tL = [];
  for (let i = 0; i < 26; i++) {
    tL[i] = { count: 0, wait: 0 };
  }
  for (const t of tasks) {
    const index = t.charCodeAt(0) - CHAR_CODE_A;
    tL[index].count++;
  }
  let ret = 0;
  let round = tasks.length;
  while (round--) {
    let choice = -1;
    for (let i = 0; i < 26; i++) {
      if (tL[i].count === 0) continue;
      const noChoice = choice === -1;
      const isQuicker = !noChoice && tL[i].wait < tL[choice].wait;
      const isMore =
        !noChoice &&
        tL[i].wait === tL[choice].wait &&
        tL[i].count > tL[choice].count;
      if (noChoice || isQuicker || isMore) {
        choice = i;
      }
    }
    const cost = tL[choice].wait + 1;
    ret += cost;
    for (let i = 0; i < 26; i++) {
      tL[i].wait = Math.max(0, tL[i].wait - cost);
    }
    tL[choice].wait = n;
    tL[choice].count--;
  }
  return ret;
};
