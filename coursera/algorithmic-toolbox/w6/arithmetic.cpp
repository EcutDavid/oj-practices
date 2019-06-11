#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long i64;
unordered_map<char, function<i64(i64 a, i64 b)>> opMap = {
    {'+', [](i64 a, i64 b) { return a + b; }},
    {'-', [](i64 a, i64 b) { return a - b; }},
    {'*', [](i64 a, i64 b) { return a * b; }}};

i64 getMaxArithVal(const vector<i64> &digits, const vector<char> &ops) {
  // m[0] -> memo for max
  // m[0] -> memo for min
  vector<vector<i64>> m[2];
  for (int i = 0; i < digits.size(); i++) {
    int width = digits.size() - i;
    for (int j = 0; j < 2; j++) {
      auto row = vector<i64>(width);
      row[0] = digits[i];
      m[j].push_back(row);
    }
  }

  for (int l = 2; l <= digits.size(); l++) {
    for (int i = 0; (i + l) <= digits.size(); i++) {
      m[0][i][l - 1] = -1e18;
      m[1][i][l - 1] = 1e18;

      for (int j = 0; j < (l - 1); j++) {
        for (int k = 0; k < 4; k++) {
          auto op = opMap[ops[i + j]];
          i64 ret = op(m[k % 2][i][j], m[k / 2][i + j + 1][l - j - 2]);
          m[0][i][l - 1] = max(m[0][i][l - 1], ret);
          m[1][i][l - 1] = min(m[1][i][l - 1], ret);
        }
      }
    }
  }
  return m[0][0][digits.size() - 1];
}

int main() {
  string str;
  cin >> str;
  vector<i64> d;
  vector<char> c;
  for (int i = 0; i < str.size(); i += 2) {
    d.push_back(str[i] - '0');
  }
  for (int i = 1; i < str.size(); i += 2) {
    c.push_back(str[i]);
  }
  cout << getMaxArithVal(d, c) << endl;
}
