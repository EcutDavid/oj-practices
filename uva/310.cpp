#include <bits/stdc++.h>
using namespace std;

int main() {
  unsigned int b, p, m;;
  while (cin >> b >> p >> m) {
    b = b % m;

    int res = 1;
    set<int> resSet = {res};
    map<int, int> indexRes, resIndex;
    indexRes[0] = res, resIndex[res] = 0;

    for (unsigned int i = 1; i <= p; i++) {
      res = res * b % m;
      if (resSet.count(res)) {
        auto width = i - resIndex[res], steps = p - i;
        res = indexRes[resIndex[res] + (steps % width)];
        break;
      } else {
        resSet.insert(res), indexRes[i] = res, resIndex[res] = i;
      }
    }

    cout << res << endl;
  }
}
