#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    if (n == 0) {
      return ret;
    }

    vector<unordered_set<string>> m(n);
    m[0] = {"()"};
    for (int i = 1; i < n; i++) {
      unordered_set<string> newS;
      for (auto d : m[i - 1]) {
        newS.insert(string("(") + d + ')');
      }
      for (int j = 0; j < (i + 1) / 2; j++) {
        for (auto d1 : m[j]) {
          for (auto d2 : m[i - j - 1]) {
            newS.insert(d1 + d2);
            newS.insert(d2 + d1);
          }
        }
      }

      m[i] = newS;
    }
    ret = vector<string>(m[n - 1].begin(), m[n - 1].end());
    return ret;
  }
};