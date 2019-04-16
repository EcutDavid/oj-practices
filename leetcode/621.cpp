#include <vector>
using namespace std;

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<pair<int, int>> tL(26);
    for (char t : tasks) {
      tL[t - 'A'].first++;
    }

    int ret = 0;
    int round = tasks.size();
    while (round--) {
      int c = -1;
      for (int i = 0; i < 26; i++) {
        if (tL[i].first == 0) continue;
        bool noChoice = c == -1;
        bool isQuicker = !noChoice && tL[i].second < tL[c].second;
        bool isMore = !noChoice && tL[i].second == tL[c].second && tL[i].first > tL[c].first;
        if (noChoice || isQuicker || isMore) {
          c = i;
        }
      }
      int cost = tL[c].second + 1;
      ret += cost;
      for (int i = 0; i < 26; i++) {
        tL[i].second = max(0, tL[i].second - cost);
      }
      tL[c].second = n;
      tL[c].first--;
    }
    return ret;
  }
};
