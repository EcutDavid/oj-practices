// TODO: simulate multiplication instead of accumulation.
#include <string>
#include <vector>

using namespace std;

class BigInt {
 public:
  vector<int> digits;

  BigInt(string raw) {
    digits.resize(raw.size());
    for (int i = 0; i < raw.size(); i++) {
      digits[i] = raw[raw.size() - i - 1] - '0';
    }
  }

  void increase(BigInt &b) {
    int loopLength = max(digits.size(), b.digits.size());
    int acc = 0;
    for (int i = 0; i < loopLength; i++) {
      if (i == digits.size()) digits.push_back(0);
      int bD = (i >= b.digits.size()) ? 0 : b.digits[i];
      int sum = digits[i] + bD + acc;

      digits[i] = sum % 10;
      acc = sum / 10;
    }
    if (acc) digits.push_back(acc);
  }

  string toString() {
    string ret = "";
    for (int i = 0; i < digits.size(); i++) {
      ret += digits[digits.size() - i - 1] + '0';
    }
    return ret;
  }
};

class Solution {
 public:
  string multiply(string x, string y) {
    if (x.size() < y.size()) swap(x, y);
    vector<BigInt> parts;
    string suffix = "";

    for (int i = 0; i < y.size(); i++) {
      if (i) suffix += '0';
      int d = y[y.size() - i - 1] - '0';
      if (d == 0) continue;

      BigInt part(x + suffix);
      for (int j = 1; j < d; j++) {
        BigInt copy(x + suffix);
        part.increase(copy);
      }
      parts.push_back(part);
    }

    if (parts.empty()) return "0";

    BigInt ret = parts.back();
    for (int i = 1; i < parts.size(); i++) {
      ret.increase(parts[i - 1]);
    }
    return ret.toString();
  }
};