#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long i64;

int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  vector<i64> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  i64 ret = 0;
  for (int i = 0; i < n; i++) {
    ret += a[i] * c[i];
  }
  cout << ret << endl;
}