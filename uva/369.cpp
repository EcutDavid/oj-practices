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

#define REP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back
#define PF push_front

di32 addDigits(di32 a, di32 b) {
  di32 answer = a.size() > b.size() ? a : b; i32 acc = 0;
  REP(i, 0, answer.size()) {
    i32 addRes = (a.size() > i ? a[i] : 0) + (b.size() > i ? b[i] : 0) + acc;
    answer[i] = addRes % 10; acc = addRes / 10;
  }
  if (acc != 0) answer.PB(acc);
  return answer;
}

di32 mulDigits(di32 digits, int num) {
  di32 answer = {}; i32 counter = 0;
  while (num) {
    if (counter != 0) digits.PF(0);
    di32 copy = digits; i32 acc = 0;
    REP(i, 0, copy.size()) {
      i32 mulRes = copy[i] * (num % 10) + acc;
      acc = mulRes / 10; copy[i] = mulRes % 10;
    }
    if (acc > 0) copy.PB(acc);

    if (counter == 0) answer = copy;
    else answer = addDigits(answer, copy);
    counter++; num /= 10;
  }
  return answer;
}

map<i32, i32> getPrimeFactors(i32 num) {
  map<i32, i32> res = {};
  REP(i, 2, num + 1) {
    while (num % i == 0) {
      res[i]++; num /= i;
    }
  }
  return res;
}

i32 main() {
  i32 n, m;
  while (cin >> n >> m) {
    if (n == 0) return 0;

    i32 oldM = m;
    if (m < (n - m)) m = n - m;

    map <i32, i32> primes = {};
    REP(i, m + 1, n + 1) {
      map <i32, i32> part = getPrimeFactors(i);
      for (auto p : part) {
        primes[p.first] += p.second;
      }
    }

    REP(i, m + 1, n + 1) {
      map <i32, i32> part = getPrimeFactors(i - m);
      for (auto p : part) {
        primes[p.first] -= p.second;
      }
    }

    di32 digits = {1};
    for (auto p : primes) {
      REP(i, 0, p.second) {
        digits = mulDigits(digits, p.first);
      }
    }

    string answer = "";
    REP(i, 0, digits.size()) {
      answer += '0' + digits[digits.size() - i - 1];
    }
    printf("%d things taken %d at a time is %s exactly.\n", n, oldM, answer.c_str());
  }
}
