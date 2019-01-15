#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n >> m;

  map<int, int> countMap;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    countMap[b] += a;
  }

  int pointer = 10, result = 0;
  while ((pointer > 0) && (n > 0)) {
    int steal = countMap[pointer] > n ? n : countMap[pointer];
    result += steal * pointer, pointer -= 1, n -= steal;
  }
  cout << result << endl;
}