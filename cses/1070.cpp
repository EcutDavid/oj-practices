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

void visit(vi32 &p, unordered_set<i32> &v, i32 length) {
  if (p.size() == length) {
    REP(i, 0, p.size() - 1) {
      if (abs(p[i] - p[i + 1]) <= 1) {
        return;
      }
    }
    REP(i, 0, p.size()) {
      cout << (i > 0 ? " " : "") << p[i];
    }
    cout << endl;
    return;
  }
  REP(i, 1, length + 1) {
    if (v.count(i)) continue;

    p.push_back(i);
    v.insert(i);
    visit(p, v, length);
    p.pop_back();
    v.erase(i);
  }
}

i32 main() {
  // code below can validate the beautiful permutation for [3, 5]
  // vi32 p;
  // unordered_set<i32> v;
  // visit(p, v, 3);
  // visit(p, v, 4);
  // visit(p, v, 5);

  i32 n;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    return 0;
  }
  if (n < 4) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  if (n == 4) {
    cout << "2 4 1 3" << endl;
    return 0;
  }
  i32 s = 1;
  while (s <= n) {
    cout << (s == 1 ? "" : " ") << s;
    s += 2;
  }
  s = 2;
  while (s <= n) {
    cout << " " << s;
    s += 2;
  }
}
