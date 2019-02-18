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

i32 main() {
  i32 n, v;
  cin >> n >> v;

  if (v >= (n - 1)) {
    cout << n - 1 << endl;
    return 0;
  }

  i32 sum = v;
  i32 rounds = n - 1 - v, i = 2;
  REP(j, 0, rounds) {
    sum += i++;
  }
  cout << sum << endl;
}
