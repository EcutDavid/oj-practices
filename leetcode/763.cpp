// Time Cost: 33 mins
// Initially come up a wrong greedy strategy.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> ret;
    unordered_map<char, int> m;

    // Build a map<char, int> m which indicates the last occ of any char.
    for (char c = 'a'; c <= 'z'; c++) {
      for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] == c) {
          m[c] = i;
          break;
        }
      }
    }

    int index = 0;
    while (index < S.size()) {
      int begin = index;
      int last = m[S[index]];
      while (begin != last) {
        int oldLast = last;
        for (int i = begin + 1; i <= last; i++) {
          last = max(last, m[S[i]]);
        }
        begin = oldLast;
      }
      ret.push_back(last - index + 1);
      index = last + 1;
    }
    return ret;
  }
};