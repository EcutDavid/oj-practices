// Spent 30 mins on learning cin/cout is slower than scanf/printf when big amount of chunked data come.
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

#define REP(i, a, b) for (i32 i = a; i < b; i++)
#define PB push_back
#define PF push_front

bool h[(int)2e6 + 1];

i32 main() {
  i32 n, m, k; cin >> n >> m >> k;

  while (m--) {
    i32 hole; scanf("%d", &hole); h[hole] = true;
  }
  if (h[1]) {
    cout << 1 << endl; return 0;
  }

  i32 bone = 1;
  REP(i, 0, k) {
    i32 a, b; scanf("%d %d", &a, &b);
    if (b == bone) swap(a, b);
    if (a != bone) continue;
    if (h[b]) {
      cout << b << endl; return 0;
    }

    bone = b;
  }
  cout << bone << endl;
}
