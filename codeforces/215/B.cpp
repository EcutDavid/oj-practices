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
  double r1 = 0, n = 0; cin >> n;
  REP(i, 0, n) {
    double num; cin >> num;
    if (num > r1) r1 = num;
  }

  vector<double> p1, p2;
  cin >> n;
  REP(i, 0, n) {
    double num; cin >> num;
    p1.push_back(num);
  }
  cin >> n;
  REP(i, 0, n) {
    double num; cin >> num;
    p2.push_back(num);
  }
  double a, b; cin >> a >> b;

  double r2 = 0;
  REP(i, 0, p1.size()) {
    REP(j, 0, p2.size()) {
      double res = r1 * sqrt(b * p1[i] / (a * p2[j] + b * p1[i]));
      if (res > r2) r2 = res;
    }
  }

  printf("%.13f\n", r2);
}
