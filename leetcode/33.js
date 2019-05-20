/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function search(nums, target) {
  let l = 0;
  let r = nums.length - 1;
  while (l <= r) {
    const mid = Math.floor((l + r) / 2);
    const midVal = nums[mid];
    if (midVal == target) return mid;

    if (nums[l] <= nums[r]) {
      if (midVal > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
      continue;
    }

    const midInLeftSegment = midVal >= nums[l];

    if (midInLeftSegment) {
      if (midVal > target && nums[l] <= target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
      continue;
    }

    if (midVal < target && nums[r] >= target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return -1;
}
