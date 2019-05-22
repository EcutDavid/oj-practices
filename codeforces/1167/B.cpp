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

map<int, set<int>> genM2(vector<int>::iterator begin, vector<int>::iterator end) {
  map<int, set<int>> ret;
  while (begin != end) {
    auto it = begin + 1;
    while (it != end) {
      ret[*begin * *it] = {*begin, *it};
      it++;
    }
    begin++;
  }
  return ret;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  vi32 raw = {4, 8, 15, 16, 23, 42};
  map<int, set<int>> m2 = genM2(raw.begin(), raw.end());

  int a1, a2, a3, a4;
  cout << "? 1 2" << endl;
  cin >> a1;
  cout << "? 2 3" << endl;
  cin >> a2;
  cout << "? 4 5" << endl;
  cin >> a3;
  cout << "? 5 6" << endl;
  cin >> a4;

  set<int> a1s = m2[a1];
  set<int> a2s = m2[a2];
  set<int> a3s = m2[a3];
  set<int> a4s = m2[a4];

  vector<int> ret(6);
  for (int d : a1s) {
    if (a2s.count(d)) ret[1] = d;
  }
  ret[0] = a1 / ret[1];
  ret[2] = a2 / ret[1];
  for (int d : a3s) {
    if (a4s.count(d)) ret[4] = d;
  }
  ret[3] = a3 / ret[4];
  ret[5] = a4 / ret[4];

  cout << "!";
  REP(i, 0, 6) {
    cout << " " << ret[i];
  }
  cout << endl;
}
