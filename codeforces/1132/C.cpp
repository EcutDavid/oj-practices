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

int getBest(int n, vector<pair<int, int>> &q) {
  unordered_map<int, int> p;
  int total = 0;
  for (auto d : q) {
    for (int i = d.first; i <= d.second; i++) {
      if (p[i] == 0) total++;
      p[i]++;
    }
  }

  int ret = 0;
  for (int i = 0; i < q.size() - 1; i++) {
    int totalCopy = total;

    vector<int> pre(n + 1);
    for (int j = 1; j <= n; j++) {
      pre[j] = pre[j - 1];
      bool collide = (j >= q[i].first) && (j <= q[i].second);
      if (collide && p[j] == 1) {
        totalCopy--;
        continue;
      }
      if (collide && p[j] == 2) {
        pre[j]++;
        continue;
      }
      if (p[j] == 1) pre[j]++;
    }
    int best = 0;
    for (int j = i + 1; j < q.size(); j++) {
      int lost = pre[q[j].second] - pre[q[j].first - 1];
      best = max(best, totalCopy - lost);
    }
    ret = max(ret, best);
  }
  return ret;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> q;
  REP(i, 0, m) {
    i32 a, b;
    cin >> a >> b;
    q.push_back({a, b});
  }
  cout << getBest(n, q) << endl;
}
