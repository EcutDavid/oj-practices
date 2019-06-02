#include <iostream>
#include <vector>

using namespace std;

int main() {
  int d, m, n;
  cin >> d >> m >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int pos = 0;
  int fuelCount = 0;
  int sIndex = -1;

  while ((pos + m < d) && (sIndex < (n - 1))) {
    int newSIndex = sIndex;
    for (int i = sIndex + 1; i < n; i++) {
      if (s[i] > (pos + m)) break;
      newSIndex = i;
    }
    if (newSIndex == sIndex) break;
    sIndex = newSIndex;
    pos = s[sIndex];
    fuelCount++;
  }

  if (pos + m < d) {
    cout << -1 << endl;
  } else {
    cout << fuelCount << endl;
  }
}