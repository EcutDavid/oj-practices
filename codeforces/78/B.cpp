#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)

int main() {
  string colors = "ROYGBIV";
  string lastFour = colors.substr(3, 4);
  int n;
  cin >> n;

  REP(i, 7, n) {
    colors += lastFour[(i - 7) % 4];
  }

  cout << colors << endl;
}
