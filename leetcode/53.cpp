#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

class Solution {
 public:
  i32 maxSubArray(vector<i32>& nums) {
    i32 edge = nums[0], best = nums[0];
    REP(i, 1, nums.size()) {
      edge = edge < 0 ? nums[i] : (edge + nums[i]);
      best = edge > best ? edge : best;
    }

    return best;
  }
};
