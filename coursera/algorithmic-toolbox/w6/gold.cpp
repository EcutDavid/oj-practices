#include <iostream>
#include <vector>

using namespace std;

int main() {
  int bagCap, n;
  cin >> bagCap >> n;
  vector<int> m(bagCap + 1);

  for (int i = 0; i < n; i++) {
    int goldW;
    cin >> goldW;
    for (int i = bagCap; i >= goldW; i--) {
      m[i] = max(m[i], m[i - goldW] + goldW);
    }
  }

  cout << m[bagCap] << endl;
}
