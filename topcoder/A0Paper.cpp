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

class A0Paper {
 public:
  string canBuild(vector<i32> A) {
    i32 expect = 1;
    REP(i, 0, A.size()) {
      if (A[i] >= expect) return "Possible";

      expect -= A[i];
      expect *= 2;
    }
    return "Impossible";
  }
};
