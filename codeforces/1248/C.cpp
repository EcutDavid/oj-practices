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

vector<string> gen(i32 len) {
  vector<string> ret;
  i32 max = pow(2, len);
  REP(i, 0, max) {
    string str;
    i32 iCopy = i;
    REP(j, 0, len) {
      str += iCopy % 2 ? 'B' : 'W';
      iCopy /= 2;
    }
    ret.push_back(str);
  }
  return ret;
}

bool validate(vector<string> &in) {
  REP(i, 0, in.size()) {
    REP(j, 0, in[0].size()) {
      char color = in[i][j];
      i32 count = 0;
      if (j > 0) {
        count += in[i][j - 1] == color;
      }
      if (j < in[0].size() - 1) {
        count += in[i][j + 1] == color;
      }
      if (i > 0) {
        count += in[i - 1][j] == color;
      }
      if (i < in.size() - 1) {
        count += in[i + 1][j] == color;
      }
      if (count > 1) return false;
    }
  }
  return true;
}

i64 M = 1e9 + 7;

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n, m;
  cin >> n >> m;
  if (n < m) swap(n, m);
  i64 bbC = 1;
  i64 bwC = 1;
  i64 wbC = 1;
  i64 wwC = 1;
  i64 ret = n == 1 ? 2 : 4;
  REP(i, 3, n + 1) {
    i64 newBbC = wbC;
    i64 newBwC = bbC + wbC;
    i64 newWbC = bwC + wwC;
    i64 newWwC = bwC;
    bbC = newBbC;
    bwC = newBwC % M;
    wbC = newWbC % M;
    wwC = newWwC;
    ret = (bbC + bwC + wwC + wbC) % M;
  }

  if (m > 1) {
    ret = (ret + m * 2 - 2) % M;
  }
  cout << ret << "\n";

  // REP(i, 2, 15) {
  //   auto g1 = gen(i);
  //   i32 count = 0;
  //   for (auto d1 : g1) {
  //     for (auto d3 : g1) {
  //       vector<string> c = {d1, d3};
  //       count += validate(c);
  //     }
  //   }
  //   PRINT(count);
  //   count = 0;
  //   for (auto d1 : g1) {
  //     for (auto d2 : g1) {
  //       for (auto d3 : g1) {
  //         vector<string> c = {d1, d2, d3};
  //         count += validate(c);
  //       }
  //     }
  //   }
  //   PRINT(count);
  //   PRINT("count");
  // }
}
