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

class Solution {
 public:
  bool isValid(string s) {
    if (s.size() % 3) return false;

    unordered_map<char, i32> cm;
    REP(i, 0, s.size()) {
      cm[s[i]]++;
      if (cm['b'] > cm['a']) return false;
      if ((cm['c'] > cm['b']) || (cm['c'] > cm['a'])) return false;
    }
    return (cm['a'] == cm['b']) && (cm['a'] == cm['c']);
  }
};