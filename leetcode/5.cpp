// TODO: there are solutions much faster need review.
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.empty()) return "";

    vector<vector<bool>> m;
    m.push_back(vector<bool>(s.size(), true));
    string best = s.substr(0, 1);

    for (int i = 2; i <= s.size(); i++) {
      vector<bool> row;
      for (int j = 0; j < (s.size() - i + 1); j++) {
        bool valid = s[j] == s[j + i - 1];
        if (i > 2) valid &= m[i - 3][j + 1];

        row.push_back(valid);
        if (valid && (i > best.size())) best = s.substr(j, i);
      }
      m.push_back(row);
    }

    return best;
  }
};