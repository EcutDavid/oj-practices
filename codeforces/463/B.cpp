#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)

int h[(int)1e5];

int main() {
  int n;
  cin >> n;
  REP(i, 0, n)
    cin >> h[i];

  int e = 0, pay = h[0];
  REP(i, 1, n) {
    int cost = h[i] - h[i - 1];
    if ((e - cost) < 0)
      pay += cost - e, e = 0;
    else
      e -= cost;
  }

  cout << pay << endl;
}