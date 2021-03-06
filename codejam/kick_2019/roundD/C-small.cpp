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

struct Visitor {
  int index;
  bool closeVise;

  void drive(i32 n) {
    index = index + (closeVise ? 1 : -1);
    if (index == -1) index = n - 1;
    if (index == n) index = 0;
  }
};

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    i32 n, g, m;
    cin >> n >> g >> m;
    vector<Visitor> v(g);
    vector<vi32> mem(n);
    // O(n)
    REP(i, 0, g) {
      i32 num;
      char key;
      cin >> num >> key;
      v[i] = { num - 1, key == 'C' };
      mem[v[i].index].push_back(i);
    }

    // O(n ^ 2)
    REP(i, 0, m) {
      vector<vi32> newMem(n);
      REP(j, 0, g) {
        v[j].drive(n);
        newMem[v[j].index].push_back(j);
      }
      REP(j, 0, n) {
        if (newMem[j].empty()) continue;
        mem[j] = newMem[j];
      }
    }

    // O(n)
    vi32 count(g);
    REP(i, 0, n) {
      for (i32 d : mem[i]) {
        count[d]++;
      }
    }

    cout << "Case #" << t << ": ";
    REP(i, 0, g) {
      cout << (i > 0 ? " " : "") << count[i];
    }
    cout << "\n";
  }
}
