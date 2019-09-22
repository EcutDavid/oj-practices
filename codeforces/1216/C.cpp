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

struct Point {
  i32 x;
  i32 y;
};

bool isInside (Point p, Point lb, Point ru) {
  return p.x >= lb.x && p.x <= ru.x && p.y >= lb.y && p.y <= ru.y;
}

i32 main() {
  Point w1, w2, ba1, ba2, bb1, bb2;
  cin
    >> w1.x >> w1.y >> w2.x >> w2.y
    >> ba1.x >> ba1.y >> ba2.x >> ba2.y
    >> bb1.x >> bb1.y >> bb2.x >> bb2.y;

  if (isInside(w1, ba1, ba2) && isInside(w2, ba1, ba2)) {
    cout << "NO\n";
    return 0;
  }
  if (isInside(w1, bb1, bb2) && isInside(w2, bb1, bb2)) {
    cout << "NO\n";
    return 0;
  }
  Point w3 = { w1.x, w2.y };
  Point w4 = { w2.x, w1.y };
  if (isInside(w1, ba1, ba2) && isInside(w3, ba1, ba2)) {
    w1 = { ba2.x, w1.y };
  }
  if (isInside(w1, ba1, ba2) && isInside(w4, ba1, ba2)) {
    w1 = { w1.x, ba2.y };
  }
  if (isInside(w2, ba1, ba2) && isInside(w3, ba1, ba2)) {
    w2 = { w2.x, ba1.y };
  }
  if (isInside(w2, ba1, ba2) && isInside(w4, ba1, ba2)) {
    w2 = { ba1.x, w2.y };
  }

  if (isInside(w1, bb1, bb2) && isInside(w2, bb1, bb2)) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
}
