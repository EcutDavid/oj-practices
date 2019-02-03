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

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool hasInter(Interval a, Interval b) {
  auto c = &a, d = &b;
  if (b.start < a.start) {
    swap(c, d);
  }
  return c->end >= d->start;
}

Interval calcInter(Interval a, Interval b) {
  auto c = &a, d = &b;
  if (b.start < a.start) {
    swap(c, d);
  }
  i32 s = min(c->end, d->start);
  i32 e = min(c->end, d->end);
  return Interval(s, e);
}

class Solution {
 public:
  vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
    vector<Interval> ret;

    auto aIt = A.begin(), bIt = B.begin();
    while (aIt != A.end() && bIt != B.end()) {
      if (hasInter(*aIt, *bIt)) {
        ret.PB(calcInter(*aIt, *bIt));
        if (aIt->end >= bIt->end) {
          bIt++;
        } else {
          aIt++;
        }
      } else {
        if (aIt->start > bIt->end) {
          bIt++;
        } else {
          aIt++;
        }
      }
    }

    return ret;
  }
};