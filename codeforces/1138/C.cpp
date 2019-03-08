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

  i32 n1, n2;
  cin >> n1 >> n2;

  vi32 a[n1], r[n1], c[n2], rMax(n1), cMax(n2);
  REP(i, 0, n1) {
    REP(j, 0, n2) {
      i32 num;
      cin >> num;
      a[i].push_back(num);
    }
  }

  unordered_map<i32, i32> m;
  REP(i, 0, n1) {
    set<i32> order;
    REP(j, 0, n2) {
      order.insert(a[i][j]);
    }
    rMax[i] = order.size();

    i32 count = 1;
    TR(order, it) {
      m[*it] = count++;
    }

    vi32 row(n2);
    REP(j, 0, n2) {
      row[j] = m[a[i][j]];
    }
    r[i] = row;
  }

  REP(i, 0, n2) {
    set<i32> order;
    REP(j, 0, n1) {
      order.insert(a[j][i]);
    }
    cMax[i] = order.size();

    i32 count = 1;
    TR(order, it) {
      m[*it] = count++;
    }

    vi32 col(n1);
    REP(j, 0, n1) {
      col[j] = m[a[j][i]];
    }
    c[i] = col;
  }

  REP(i, 0, n1) {
    REP(j, 0, n2) {
      i32 mid = max(r[i][j], c[j][i]);
      i32 maxVal = max(cMax[j] - c[j][i] + mid, rMax[i] - r[i][j] + mid);
      cout << (j == 0 ? "" : " ") << maxVal;
    }
    cout << "\n";
  }
}
