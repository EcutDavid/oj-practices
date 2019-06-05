#include <iostream>
#include <vector>

using namespace std;

int main() {
  int w, n;
  cin >> w >> n;
  vector<int> m(w + 1);

  for (int i = 0; i < n; i++) {
    int goldW;
    cin >> goldW;
    for (int i = w; i >= goldW; i--) {
      m[i] = max(m[i], m[i - goldW] + goldW);
    }
  }

  cout << m[w] << endl;
}
