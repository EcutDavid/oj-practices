#include <bits/stdc++.h>
using namespace std;

typedef int i32;
typedef pair<i32, i32> pi32;

class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    priority_queue<pi32> q;
    unordered_map<int, int> m;
    for (int val : barcodes) {
      m[val]++;
    }
    for (auto d : m) {
      q.push({d.second, d.first});
    }

    vector<int> ret;
    while (!q.empty()) {
      auto fir = q.top();
      q.pop();
      fir.first--;
      ret.push_back(fir.second);
      if (q.empty()) continue;
      auto sec = q.top();
      q.pop();
      sec.first--;
      ret.push_back(sec.second);

      if (fir.first) q.push(fir);
      if (sec.first) q.push(sec);
    }
    return ret;
  }
};

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
}
