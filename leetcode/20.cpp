// This solution is very slow, TODO: find a better solution.

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

set<char> open = {'(', '[', '{'};
set<char> close = {')', ']', '}'};
map<char, char> relation = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

class Solution {
 public:
  bool isValid(string s) {
    if (s.empty()) return true;
    if (close.count(s[0])) return false;

    i32 counter = 1, index = -1;
    REP(i, 1, s.size()) {
      if (s[i] == s[0]) counter++;
      if (s[i] == relation[s[0]]) counter--;
      if (counter == 0) {
        index = i;
        break;
      }
    }
    if (index == -1) return false;
    return isValid(s.substr(1, index - 1)) && isValid(s.substr(index + 1));
  }
};