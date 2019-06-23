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

void deduceIncs(vector<pi32> &a, int l, int r, vector<int> &incs) {
  int incCount = a.size() - 2;
  if ((a[r].first - a[l].first) % incCount == 0) {
    incs.push_back((a[r].first - a[l].first) / incCount);
  }
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  if (n == 2) {
    cout << 1 << endl;
    return 0;
  }
  vector<pi32> a;
  REP(i, 0, n) {
    i32 num;
    cin >> num;
    a.push_back({num, i + 1});
  }

  sort(all(a));
  vector<int> incs;
  // Case 1: delete the head.
  deduceIncs(a, 1, n - 1, incs);
  // Case 2: delete someone from mid.
  deduceIncs(a, 0, n - 1, incs);
  // Case 3: delete the tail.
  deduceIncs(a, 0, n - 2, incs);

  for (int inc : incs) {
    i32 id = a[0].second;
    i32 mismatchCount = 0;

    REP(i, 0, n - 1) {
      if ((a[i + 1].first - a[i].first) == inc) continue;
      mismatchCount++;

      if (i == n - 2) {
        id = a[i + 1].second;
        continue;
      }

      // If a[i] is good, rm a[i + 1]
      if ((a[i + 2].first - a[i].first == inc)) {
        id = a[i + 1].second;
        i++;
        continue;
      }

      // If a[i + 1] is good, rm a[i]
      if ((a[i + 2].first - a[i + 1].first == inc)) {
        id = a[i].second;
        continue;
      }

      // If both bad
      mismatchCount++;
    }

    if (mismatchCount > 1) continue;
    cout << id << endl;
    return 0;
  }

  cout << -1 << endl;
}
