#include <math.h>
#include <algorithm>
#include <vector>

using std::min;
using std::vector;

class Solution {
 public:
  int numSquares(int n) {
    int maxB = sqrt(n);

    vector<int> memo(n + 1);
    for (int i = 1; i <= n; i++) {
      memo[i] = i;
      for (int j = 1; j <= maxB; j++) {
        if ((j * j) > i) break;
        memo[i] = min(memo[i], memo[i - j * j] + 1);
      }
    }

    return memo[n];
  }
};