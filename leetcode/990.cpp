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

class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    vector<unordered_set<char>> g;
    TR(equations, it) {
      if ((*it)[1] != '=') continue;
      auto gSub = find_if(all(g), [it](unordered_set<char> sub) { return sub.count((*it)[0]) || sub.count((*it)[3]); });
      if (gSub != g.end()) {
        gSub->insert((*it)[0]);
        gSub->insert((*it)[3]);
      } else {
        g.push_back({(*it)[0], (*it)[3]});
      }
    }

    TR(equations, it) {
      if ((*it)[1] == '=') continue;
      if ((*it)[0] == (*it)[3]) return false;

      auto sub1 = find_if(all(g), [it](unordered_set<char> sub) { return sub.count((*it)[0]); });
      auto sub2 = find_if(all(g), [it](unordered_set<char> sub) { return sub.count((*it)[3]); });
      if (sub1 == g.end() || sub2 == g.end()) continue;
      if (sub1 == sub2) return false;
    }
    return true;
  }
};
