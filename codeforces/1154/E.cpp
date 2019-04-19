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

  i32 n, k;
  cin >> n >> k;
  vi32 a(n);
  vector<pi32> q;
  i32 qIndex = 0;
  set<i32> indexS;
  REP(i, 0, n) {
    cin >> a[i];
    q.push_back({a[i], i});
    indexS.insert(i);
  }
  sort(q.rbegin(), q.rend());

  vector<bool> t1Flag(n);
  bool isT1 = true;

  while (!indexS.empty()) {
    while (!indexS.count(q[qIndex].second)) qIndex++;
    i32 best = q[qIndex].second;
    vi32 targets = {best};

    auto it = indexS.find(best);
    i32 count = 0;
    while (it != indexS.begin()) {
      --it;
      targets.push_back(*it);
      if (++count == k) break;
    }

    it = indexS.find(best);
    count = 0;
    while (it != indexS.end()) {
      if (++it == indexS.end()) break;
      targets.push_back(*it);
      if (++count == k) break;
    }

    TR(targets, target) {
      indexS.erase(*target);
      if (isT1) t1Flag[*target] = true;
    }

    isT1 = !isT1;
  }
  REP(i, 0, n) {
    cout << (t1Flag[i] ? "1" : "2");
  }
  cout << endl;
  return 0;
}
