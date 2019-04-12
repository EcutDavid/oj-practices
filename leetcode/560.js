// TOOD: investigate on faster solutions.
function subarraySum(nums, k) {
  const prefix = [0];
  let pointer = 0;
  for (const num of nums) {
    prefix.push(prefix[pointer++]);
    prefix[pointer] += num;
  }

  let ret = 0;
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length + 1; j++) {
      ret += prefix[j] - prefix[i] === k ? 1 : 0;
    }
  }
  return ret;
}
