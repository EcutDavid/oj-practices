#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> f(2);
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    int newVal = (f[0] + f[1]) % 10;
    f[0] = f[1];
    f[1] = newVal;
  }
  cout << (n == 0 ? 0 : f[1]) << endl;
}