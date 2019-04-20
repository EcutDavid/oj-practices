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

unordered_set<string> reduceDup(const vector<string>& src) {
  unordered_set<string> ret;

  for (string seq : src) {
    bool works = true;
    for (string comp : src) {
      if (comp.size() >= seq.size()) continue;
      if (comp == seq.substr(0, comp.size())) {
        works = false;
        break;
      }
    }
    if (works) ret.insert(seq);
  }

  return ret;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    i64 n, p;
    cin >> n >> p;
    vector<string> seqs(p);
    REP(i, 0, p) {
      cin >> seqs[i];
    }
    auto s = reduceDup(seqs);
    i64 total = i64(1) << n;
    for (string seq : s) {
      total -= i64(1) << (n - i64(seq.size()));
    }
    cout << "Case #" << t << ": " << total << "\n";
  }
}
