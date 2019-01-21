// The initial offer is an edge case, can remove this edge case via norminize the data.
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

i32 main() {
  i32 a, b, c, d;
  cin >> a >> b >> c >> d;
  a -= b; c += d;
  while(true) {
    //P offer
    a += b;
    if (a > (c - d)) {
      cout << a << endl;
      return 0;
    }

    //T offer
    c -= d;
    if (c < (a + b)) {
      cout << c << endl;
      return 0;
    }
  }
}
