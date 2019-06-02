#include <iostream>
#include <vector>

using namespace std;

int scanInv(vector<int>& nums, int l, int m, int r) {
  int rp = m + 1;
  int ret = 0;
  while (l <= m) {
    while (rp <= r && nums[l] > nums[rp]) {
      rp++;
    }
    ret += rp - m - 1;
    l++;
  }
  return ret;
}

int merge(vector<int>& nums, int l, int m, int r) {
  vector<int> tmp(r - l + 1);
  int ret = scanInv(nums, l, m, r);

  int lp = l;
  int rp = m + 1;
  int ti = 0;

  while (lp <= m && rp <= r) {
    int item = nums[lp++];
    if (item > nums[rp]) {
      item = nums[rp++];
      lp--;
    }
    tmp[ti++] = item;
  }
  while (lp <= m) tmp[ti++] = nums[lp++];
  while (rp <= r) tmp[ti++] = nums[rp++];
  for (int i = l; i <= r; i++) {
    nums[i] = tmp[i - l];
  }
  return ret;
}

void mergeSort(vector<int>& nums, int l, int r, int& ret) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  mergeSort(nums, l, mid, ret);
  mergeSort(nums, mid + 1, r, ret);
  ret += merge(nums, l, mid, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  int count = 0;
  mergeSort(nums, 0, n - 1, count);
  cout << count << endl;
}