/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function(nums) {
  if (!nums.length) return 0;
  const copy = nums.slice().sort((a, b) => a - b);

  let left = 0;
  let right = nums.length - 1;

  while (left < nums.length && nums[left] == copy[left]) {
    left++;
  }
  while (right > left && nums[right] == copy[right]) {
    right--;
  }
  return right - left + 1;
};
