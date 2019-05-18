function robVector(nums) {
  let m = [0, 0];
  for (const n of nums) {
    const newM = [Math.max(m[0], m[1]), n + m[0]];
    m = newM;
  }
  return Math.max(m[0], m[1]);
}

// robLinkedList
var rob = function(nums) {
  const l = nums.length;
  if (l == 0) return 0;
  if (l == 1) return nums[0];
  return Math.max(robVector(nums.slice(0, l - 1)), robVector(nums.slice(1, l)));
};
