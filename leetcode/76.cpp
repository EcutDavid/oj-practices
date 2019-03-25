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

bool validate(unordered_map<char, i64>& cMap, unordered_map<char, i64>& m) {
  TR(cMap, it) {
    if (m[it->first] < it->second) return false;
  }
  return true;
}

class Solution {
 public:
  string minWindow(string s, string t) {
    if (t == "") return "";

    unordered_map<char, i64> cMap, m;
    TR(t, it) {
      cMap[*it]++;
    }

    string ans = "";
    i64 l = 0, r = 0;
    while (l < s.size() && r <= s.size()) {
      if (!validate(cMap, m)) {
        if (r == s.size()) break;
        r++;
        if (cMap[s[r - 1]]) {
          m[s[r - 1]]++;
        };
      } else {
        l++;
        if (cMap[s[l - 1]]) {
          m[s[l - 1]]--;
        };
      }

      if (!validate(cMap, m)) continue;
      auto newAns = s.substr(l, r - l);
      if (ans == "") ans = newAns;
      if (ans.size() > newAns.size()) ans = newAns;
    }

    return ans;
  }
};