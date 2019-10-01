#include <bits/stdc++.h>
using namespace std;

typedef int i32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)

// Assumes:
//   1. A number would not get minus by another number smaller than it.
//   2. The number would not come from a "negative value".
class BigNumber {
  string digits;

 public:
  BigNumber(string num) {
    digits = num;
  }

  void add(BigNumber& num) {
    i32 len = max(digits.size(), num.getDigits().size());
    i32 acc = 0;
    vector<char> parts;
    REP(i, 0, len) {
      i32 sum = acc + getDigitValue(i) + num.getDigitValue(i);
      acc = sum / 10;
      parts.push_back(sum % 10 + '0');
    }
    if (acc) parts.push_back(acc + '0');
    reverse(all(parts));
    digits = string(all(parts));
  }

  void minus(BigNumber& num) {
    i32 len = max(digits.size(), num.getDigits().size());
    i32 acc = 0;
    vector<char> parts;
    REP(i, 0, len) {
      i32 sum = getDigitValue(i) - num.getDigitValue(i) - acc;
      acc = sum < 0 ? 1 : 0;
      sum = sum < 0 ? sum + 10 : sum;

      parts.push_back(sum % 10 + '0');
    }
    reverse(all(parts));

    digits = string(all(parts));
    i32 frontZeroCount = 0;
    REP(i, 0, len) {
      if (digits[i] != '0') break;
      frontZeroCount++;
    }
    digits = digits.substr(frontZeroCount);
  }

  // Assumes times belongs to [1, 9].
  void multiply(int times) {
    i32 acc = 0;
    vector<char> parts;
    REP(i, 0, digits.size()) {
      i32 sum = getDigitValue(i) * times + acc;
      acc = sum / 10;

      parts.push_back(sum % 10 + '0');
    }
    if (acc) parts.push_back(acc + '0');
    reverse(all(parts));

    digits = string(all(parts));
  }

  void multiplyTen(i32 times) {
    digits += string(times, '0');
  }

  i32 getDigitValue(int index) {
    return digits.size() > index ? digits[digits.size() - index - 1] - '0' : 0;
  }

  string getDigits() {
    return digits;
  }
};

void printLine(i32 width, string& content) {
  cout << string(width - content.size(), ' ') << content << "\n";
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;

  REP(i, 0, n) {
    string raw;
    cin >> raw;

    auto symbol = find_if(all(raw), [](char c) {
      return c == '+' || c == '-' || c == '*';
    });

    auto a = new BigNumber(raw.substr(0, symbol - raw.begin()));
    auto b = new BigNumber(raw.substr(symbol - raw.begin() + 1));
    auto lineFir = a->getDigits();
    auto lineSec = *symbol + b->getDigits();

    if (*symbol != '*') {
      if (*symbol == '+')
        a->add(*b);
      else
        a->minus(*b);

      auto lineLast = a->getDigits();
      string div = string(max(lineSec.size(), lineLast.size()), '-');
      i32 width = max(lineFir.size(), div.size());
      printLine(width, lineFir);
      printLine(width, lineSec);
      printLine(width, div);
      printLine(width, lineLast);
      cout << "\n";
      continue;
    }

    auto bDigits = b->getDigits();
    reverse(all(bDigits));  // Make life easier, as bDigits[0] is the last num without reverse.
    auto ret = new BigNumber("0");
    vector<string> parts;
    REP(j, 0, bDigits.size()) {
      i32 digit = bDigits[j] - '0';
      if (digit == 0) {
        parts.push_back("0" + string(j, ' '));
        continue;
      }
      BigNumber aCopy = *a;
      aCopy.multiply(digit);
      parts.push_back(aCopy.getDigits() + string(j, ' '));
      aCopy.multiplyTen(j);
      ret->add(aCopy);
    }

    auto lineLast = ret->getDigits();
    i32 width = max(max(lineFir.size(), lineSec.size()), lineLast.size());

    printLine(width, lineFir);
    printLine(width, lineSec);

    if (parts.size() == 1) {
      string div = string(max(lineSec.size(), lineLast.size()), '-');
      printLine(width, div);
      printLine(width, lineLast);
      cout << "\n";
      continue;
    }

    string divFir = string(max(parts[0].size(), lineSec.size()), '-');
    printLine(width, divFir);
    for (auto part : parts) {
      printLine(width, part);
    }
    string divSec = string(max(parts[parts.size() - 1].size(), lineLast.size()), '-');
    printLine(width, divSec);
    printLine(width, lineLast);
    cout << "\n";
  }
}
