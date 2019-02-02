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
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n;
  cin >> n;
  while (n--) {
    string line;
    cin >> line;
    i32 rxcyC = -1;
    REP(i, 1, line.size() - 1) {
      if (line[i] >= 'A' && line[i] <= 'Z' && line[i - 1] >= '0' && line[i - 1] <= '9') {
        rxcyC = i;
        break;
      }
    }

    if (rxcyC != -1) {
      i32 c = atoi(line.substr(rxcyC + 1).c_str());
      string cStr = "";

      while (c) {
        // Mapping 1-indexed to 0-indexed.
        char dig = 'A' + (c - 1) % 26;
        cStr = dig + cStr;
        c = (c - 1) / 26;
      }
      cout << cStr << line.substr(1, rxcyC - 1) << "\n";
    } else {
      auto rIt = find_if(all(line), [](char a) { return a >= '0' && a <= '9'; });
      auto c = accumulate(line.begin(), rIt, 0, [](i32 sum, char dig) { return sum * 26 + dig - 'A' + 1; });
      cout << "R" << string(rIt, line.end()) << "C" << c << "\n";
    }
  }
}
