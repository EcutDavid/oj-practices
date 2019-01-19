#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef int i32;
typedef unsigned long long u64;
typedef unsigned int u32;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back

void countGcdSteps(i64 a, i64 b, vector<int> *choices) {
  if (b > a)
    return countGcdSteps(b, a, choices);

  if (a % b == 0)
    return;

  (*choices).PB(a / b == 1 ? 1 : 2);
  countGcdSteps(b, a % b, choices);
}

int main() {
  i64 a, b;
  while(cin >> a >> b) {
    if (a == 0)
      break;

    vector<int> choices = {};
    countGcdSteps(a, b, &choices);

    bool win = true;
    REP(i, 0, choices.size()) {
      if (choices[choices.size() - i - 1] == 1)
        win = !win;
      else
        win = true;
    }

    cout << (win ? "Stan" : "Ollie") << " wins" << endl;
  }
}
