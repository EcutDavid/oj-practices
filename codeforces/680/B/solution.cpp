#include <iostream>
using namespace std;

int main() {
  int n, index;
  cin >> n >> index;
  index--;

  bool c[n];
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    c[i] = num == 1;
  }

  int total = c[index] ? 1 : 0;
  for (int i = 1; i < 100; i++) {
    int l = index - i, r = index + i;
    if ((l >= 0) && (r < n) && c[l] && c[r])
      total += 2;

    if ((l >= 0) && (r >= n) && c[l])
      total++;

    if ((l < 0) && (r < n) && c[r])
      total++;
  }

  cout << total << endl;
}