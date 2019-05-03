#include <string>

using std::string;
using std::to_string;

class Solution {
 public:
  string baseNeg2(int n) {
    if (n == 0) return "0";
    string ret;
    int base = -2;  // Be more general
    while (n) {
      ret = to_string(abs(n % base)) + ret;
      if (n % base != 0 && n < 0) {
        n += n % base;
      }
      n /= base;
    }
    return ret;
  }
};