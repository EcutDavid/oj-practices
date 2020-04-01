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

int findSetRep(vector<int>& rep, int n) {
  while (rep[n] != n) {
    n = rep[n];
  }
  return n;
}

void joinSets(vector<int>& rep, vector<int>& size, int x, int y) {
  if (size[y] > size[x]) {
    swap(x, y);
  }
  rep[y] = x;
  size[x] += size[y];
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    int n, m;
    cin >> n >> m;
    vector<int> size(n + 1, 1);
    vector<int> rep(n + 1);
    REP(i, 1, n + 1) {
      rep[i] = i;
    }

    int setCount = n;
    int cost = 0;
    REP(i, 0, m) {
      int x, y;
      cin >> x >> y;

      int xRep = findSetRep(rep, x);
      int yRep = findSetRep(rep, y);
      if (xRep == yRep) continue;

      joinSets(rep, size, xRep, yRep);
      setCount--;
      cost++;
    }

    cost += (setCount - 1) * 2;

    cout << "Case #" << t << ": ";
    cout << cost << "\n";
  }
}
