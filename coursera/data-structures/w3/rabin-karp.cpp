#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// First prime that bigger than 5e5(the max length of P) is 500009.
// 1. calculate p and t0.
// 2. iterate through the range, when there is a match, do full check.

bool check(string &p, string &t, int l, int r) {
  bool ret = true;
  for (int i = 0; i <= (r - l); i++) {
    if (p[i] != t[l + i]) {
      ret = false;
      break;
    }
  }
  return ret;
}

const int m = 5e5 + 9;

int main() {
  string pS, tS;
  cin >> pS >> tS;

  int h = 1;
  int p = 0, t = 0;
  for (int i = 0; i < pS.size(); i++) {
    p = (p * 256 + pS[i]) % m;
    t = (t * 256 + tS[i]) % m;
    if (i > 0) h = h * 256 % m;
  }

  int lastIndex = tS.size() - pS.size();
  vector<int> indexes;

  for (int i = 0; i <= lastIndex; i++) {
    if (p == t && check(pS, tS, i, i + pS.size() - 1)) {
      indexes.push_back(i);
    }

    if (i != lastIndex) {
      t = ((t + m - (tS[i] * h % m)) * 256 + tS[i + pS.size()]) % m;
    }
  }

  for (int i = 0; i < indexes.size(); i++) {
    cout << (i > 0 ? " " : "") << indexes[i];
  }
  cout << endl;
}