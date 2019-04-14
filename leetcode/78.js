function genS(level, set, arr, ret) {
  if (level == arr.length) {
    ret.push(set.slice());
    return;
  }
  set.push(arr[level]);
  genS(level + 1, set, arr, ret);
  set.pop();
  genS(level + 1, set, arr, ret);
}

var subsets = function(nums) {
  const ret = [];
  genS(0, [], nums, ret);
  return ret;
};
