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

  string a, b;
  while (getline(cin, a)) {
    getline(cin, b);
    map<char, i32> aCMap, bCMap;
    TR(a, it) {
      aCMap[*it]++;
    }
    TR(b, it) {
      bCMap[*it]++;
    }
    string result;
    REP(i, 0, 26) {
      result += string(min(aCMap['a' + i], bCMap['a' + i]), (char)('a' + i));
    }
    cout << result << "\n";
  }
}
