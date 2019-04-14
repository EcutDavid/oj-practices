var fourSumCount = function(A, B, C, D) {
  const cdMap = new Map();
  C.forEach(c => {
    D.forEach(d => {
      const sum = c + d;
      const count = cdMap.get(sum);
      cdMap.set(sum, 1 + (count ? count : 0));
    });
  });

  let ret = 0;
  A.forEach(a => {
    B.forEach(b => {
      const target = -(a + b);
      const count = cdMap.get(target);
      ret += count ? count : 0;
    });
  });
  return ret;
};
