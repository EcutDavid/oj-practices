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

void add(vector<i32>& A, i32 dig, i32 pos) {
  while ((pos + 1) > A.size()) {
    A.insert(A.begin(), 0);
  }
  REP(i, 0, A.size() - pos) {
    i32 index = A.size() - 1 - i - pos;
    i32 ret = A[index] + dig;
    A[index] = ret % 10;
    dig = ret / 10;
  }
  if (dig) {
    A.insert(A.begin(), dig);
  }
}

class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    i32 pos = 0;
    while (K) {
      add(A, K % 10, pos++);
      K /= 10;
    }
    return A;
  }
};