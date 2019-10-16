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
  cin >> n;
  vector<i64> c1(n), c2(n), c3(n);
  REP(i, 0, n) cin >> c1[i];
  REP(i, 0, n) cin >> c2[i];
  REP(i, 0, n) cin >> c3[i];
  vector<vector<i64>> c = {c1, c2, c3};
  vector<vector<i32>> adj(n);
  REP(i, 0, n - 1) {
    i32 a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    if (adj[a].size() > 2 || adj[b].size() > 2) {
      cout << -1 << "\n";
      return 0;
    }
  }
  i32 head = -1;
  REP(i, 0, n) {
    if (adj[i].size() == 1) {
      head = i;
      break;
    }
  }
  if (head == -1) {
    cout << -2 << "\n";
    return -1;
  }

  i64 ret = -1;
  vi32 bestRecord(n);
  REP(i, 0, 3) {
    REP(j, 0, 3) {
      if (i == j) continue;
      i32 prev = head;
      i32 cur = adj[prev][0];
      i64 localRet = c[i][prev] + c[j][cur];
      vi32 record(n);
      record[prev] = i;
      record[cur] = j;
      while(adj[cur].size() != 1) {
        i32 next = adj[cur][0];
        if (next == prev) {
          next = adj[cur][1];
        }
        i32 nextColor = 3 - record[prev] - record[cur];
        record[next] = nextColor;
        localRet += c[nextColor][next];

        prev = cur;
        cur = next;
      }
      if (ret == -1) {
        ret = localRet;
        bestRecord = record;
      }
      if (localRet < ret) {
        ret = localRet;
        bestRecord = record;
      }
    }
  }

  cout << ret << "\n";
  REP(i, 0, n) {
    cout << (i > 0 ? " " : "") << bestRecord[i] + 1;
  }
  cout << "\n";
}
