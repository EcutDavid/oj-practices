#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
 public:
  vector<string> findStrobogrammatic(int n) {
    if (n == 0) return {};
    vector<vector<string>> m(max(n, 2));
    vector<vector<string>> c(2);

    m[0] = {"0", "1", "8"};
    m[1] = {"11", "69", "96", "88"};
    c[0] = m[0];
    c[1] = m[1];
    c[1].push_back("00");

    for (int i = 2; i < n; i++) {
      int prev = i / 2 * 2 - 1;
      for (auto s1 : m[prev]) {
        for (auto s2 : c[i % 2]) {
          int halfW = (prev + 1) / 2;
          m[i].push_back(s1.substr(0, halfW) + s2 + s1.substr(halfW, halfW));
        }
      }
    }
    return m[n - 1];
  }
};