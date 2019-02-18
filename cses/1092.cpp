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

void show(vi32 a) {
  cout << a.size() << "\n";
  REP(i, 0, a.size()) {
    cout << (i > 0 ? " " : "") << a[i];
  }
  cout << "\n";
}

i32 main() {
  i32 n;
  cin >> n;

  if (n * (n + 1) / 2 % 2) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES\n";
  vi32 s1, s2;
  if (n % 2) s1.push_back(1);
  bool oddTurn = true;
  REP(i, n % 2 + 1, n) {
    if (oddTurn) {
      s1.push_back(i);
      s2.push_back(i + 1);
    } else {
      s1.push_back(i + 1);
      s2.push_back(i);
    }
    oddTurn = !oddTurn;
    i++;
  }
  show(s1);
  show(s2);
}
