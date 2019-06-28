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
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ret;
    vi32 patternUpper(1);
    REP(i, 0, pattern.size()) {
      if (pattern[i] >= 'A' && pattern[i] <= 'Z') {
        patternUpper.push_back(i);
      }
    }
    patternUpper.push_back(pattern.size());
    vector<vector<char>> segment(patternUpper.size() - 1);
    REP(i, 0, patternUpper.size() - 1) {
      REP(j, patternUpper[i] + 1, patternUpper[i + 1]) {
        segment[i].push_back(pattern[j]);
      }
    }

    TR(queries, q) {
      vi32 qUpper(1);
      REP(i, 0, q->size()) {
        if ((*q)[i] >= 'A' && (*q)[i] <= 'Z') {
          qUpper.push_back(i);
        }
      }
      qUpper.push_back(q->size());
      if (qUpper.size() != patternUpper.size()) {
        ret.push_back(false);
        continue;
      }

      bool canContinue = true;
      REP(i, 1, qUpper.size() - 1) {
        if ((*q)[qUpper[i]] != pattern[patternUpper[i]]) {
          canContinue = false;
          break;
        }
      }
      if (!canContinue) {
        ret.push_back(false);
        continue;
      }
      REP(i, 0, qUpper.size() - 1) {
        auto pSeg = segment[i];
        i32 p1 = 0;
        REP(j, qUpper[i] + 1, qUpper[i + 1]) {
          if (p1 == pSeg.size()) {
            break;
          }
          if ((*q)[j] == pSeg[p1]) p1++;
        }
        if (p1 != pSeg.size()) canContinue = false;
        if (!canContinue) break;
      }
      if (!canContinue) {
        ret.push_back(false);
        continue;
      }
      ret.push_back(true);
    }
    return ret;
  }
};