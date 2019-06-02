#include <iostream>
#include <vector>

using namespace std;

int main() {
  int m;

  cin >> m;
  int total = m / 10;
  total += (m % 10) / 5;
  total += m % 5;

  cout << total << endl;
}