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

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  unordered_map<i32, queue<i32>> m;

  REP(i, 0, n) {
    i32 num;
    cin >> num;
    if (m[num].size() <= 1) {
      m[num].push(i);
      continue;
    }
    if (m[num].front() == -1) continue;

    i32 t = m[num].front();
    m[num].pop();
    if ((m[num].front() - t) == (i - m[num].front())) {
      m[num].push(i);
    } else {
      m[num].pop();
      m[num].push(-1);
      m[num].push(-1);
    }
  }

  i32 total = 0;
  string output;
  REP(i, 1, i32(1e5 + 1)) {
    if (m[i].empty()) continue;
    if (m[i].front() == -1) continue;
    total++;

    if (m[i].size() == 1) {
      output += to_string(i) + " 0\n";
      continue;
    }

    i32 t = m[i].front();
    m[i].pop();
    output += to_string(i) + " " + to_string(m[i].front() - t) + "\n";
  }

  cout << total << "\n"
       << output;
}
