#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> f(n + 1);
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  cout << f[n] << endl;
}