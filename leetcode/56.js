var merge = function(intervals) {
  const merged = new Set();
  intervals.forEach((d, i) => {
    for (let j = i + 1; j < intervals.length; j++) {
      if (d[0] > intervals[j][1] || d[1] < intervals[j][0]) {
        continue;
      }
      merged.add(i);
      intervals[j][0] = Math.min(intervals[j][0], d[0]);
      intervals[j][1] = Math.max(intervals[j][1], d[1]);
      break;
    }
  });
  const ret = [];
  intervals.forEach((d, i) => {
    if (merged.has(i)) return;
    ret.push(d);
  });
  return ret;
};
