#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back

int main() {
  i32 n;
  cin >> n;
  while(n--) {
    u32 l, r, d;
    cin >> l >> r >> d;

    if ((l / d > 1) || ((l / d == 1) && (l % d > 0))) {
      cout << d << "\n";
      continue;
    }

    cout << (r / d + 1) * d << "\n";
  }
}
