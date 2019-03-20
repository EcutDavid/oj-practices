#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;

    int best = 1, left = 0;
    vector<int> m(255, -1);  // ASCII only & using vec instead of map for speed.
    for (int i = 0; i < s.size(); i++) {
      if (m[s[i]] != -1) {
        left = max(m[s[i]] + 1, left);
      }
      m[s[i]] = i;
      best = max(best, i - left + 1);
    }
    return best;
  }
};