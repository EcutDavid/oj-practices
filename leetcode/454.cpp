#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> cdMap;
    for (auto c = C.begin(); c != C.end(); c++) {
      for (auto d = D.begin(); d != D.end(); d++) {
        cdMap[*c + *d]++;
      }
    }
    int ret = 0;
    for (auto a = A.begin(); a != A.end(); a++) {
      for (auto b = B.begin(); b != B.end(); b++) {
        ret += cdMap[-*a - *b];
      }
    }
    return ret;
  }
};