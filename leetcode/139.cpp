#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> m(s.size() + 1);
    m[0] = true;

    for (int i = 1; i <= s.size(); i++) {
      for (auto w : wordDict) {
        if (w.size() > i) continue;
        if (s.substr(i - w.size(), w.size()) == w && m[i - w.size()]) {
          m[i] = true;
          break;
        }
      }
    }

    return m[s.size()];
  }
};