#include <bits/stdc++.h>
using namespace std;

typedef int i32;
#define REP(i, a, b) for (auto i = a; i < b; i++)

const i32 passLen = 5, ruleLen = 3;

string numToStr(i32 num) {
  string base = to_string(num);
  return string(passLen - base.size(), '0') + base;
}

bool validate(string pass, vector<string>& rules) {
  REP(i, 0, rules.size()) {
    auto pointer = pass.begin();
    REP(j, 0, ruleLen) {
      auto next = find(pointer, pass.end(), rules[i][j]);
      if (next == pass.end()) return false;
      pointer = ++next;
    }
  }
  return true;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  vector<string> rules;
  string rule;
  while (cin >> rule) {
    rules.push_back(rule);
  }
  cout << "Result listed below, empty result means impossible\n";

  // Length of password is five, so 1e6 yields all the comb.
  REP(i, 0, i32(1e5)) {
    string pass = numToStr(i);
    if (validate(pass, rules)) {
      cout << pass << "\n";
    }
  }
}
