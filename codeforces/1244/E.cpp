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
#define PRINT(x) cout << #x ": " << (x) << endl;
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10);

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  i64 k;
  cin >> n >> k;
  vi32 a(n);
  map<i32, i32> nums;
  REP(i, 0, n) {
    i32 num;
    cin >> num;
    nums[num]++;
  }
  while(nums.size() != 1 && k > 0) {
    // Choose the smaller side to move.
    auto target = nums.begin();
    auto next = ++nums.begin();
    if ((--nums.end())->second < target->second) {
      target = --nums.end();
      next = --nums.end();
      next--;
    }
    i64 costMax = abs(i64(next->first - target->first)) * target->second;
    if (k >= costMax) {
      nums[next->first] += target->second;
      nums.erase(target);
      k -= costMax;
      continue;
    }

    i64 distance = k / target->second;
    k = 0;
    if (distance == 0) {
      continue;
    }

    if (target->first > next->first) {
      nums[target->first - distance] = target->second;
    } else {
      nums[target->first + distance] = target->second;
    }
    nums.erase(target);
  }

  cout << ((--nums.end())->first - nums.begin()->first) << "\n";
}
