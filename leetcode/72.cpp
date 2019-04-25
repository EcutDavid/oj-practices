#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDistance(string a, string b) {
    vector<vector<int>> memo(b.size() + 1);
    for (int i = 0; i <= b.size(); i++) {
      memo[i] = vector<int>(a.size() + 1);
      memo[i][0] = i;
      for (int j = 1; j <= a.size(); j++) {
        if (i == 0) {
          memo[i][j] = j;
          continue;
        }
        int effort = memo[i - 1][j - 1] + 1;
        if (b[i - 1] == a[j - 1]) effort -= 1;
        effort = min(effort, memo[i - 1][j] + 1);
        effort = min(effort, memo[i][j - 1] + 1);
        memo[i][j] = effort;
      }
    }
    return memo[b.size()][a.size()];
  }
};