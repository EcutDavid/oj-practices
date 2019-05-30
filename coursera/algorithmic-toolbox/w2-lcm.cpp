#include <iostream>
#include <vector>

typedef long long i64;

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << i64(a) / gcd(a, b) * i64(b) << endl;
}