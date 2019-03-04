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
  vector<string> commonChars(vector<string>& A) {
    map<char, i32> cMap;
    TR(A[0], it) {
      cMap[*it]++;
    }
    REP(i, 1, A.size()) {
      map<char, i32> temp;
      TR(A[i], it) {
        temp[*it]++;
      }
      TR(cMap, it) {
        cMap[it->first] = min(it->second, temp[it->first]);
      }
    }

    vector<string> ret;
    TR(cMap, it) {
      REP(i, 0, it->second) {
        ret.push_back(string(1, it->first));
      }
    }
    return ret;
  }
};