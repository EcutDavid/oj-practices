#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)

int main() {
  int num = 0, digitCount = 0;
  char digit;
  while (cin >> digit)
    num += digit - '0', digitCount++;

  if (digitCount == 1) {
    cout << 0 << endl;
    return 0;
  }

  int transformCount = 1;
  while (num >= 10) {
    int numCopy = num;
    num = 0;
    while(numCopy)
      num += numCopy % 10, numCopy /= 10;

    transformCount++;
  }

  cout << transformCount << endl;
}
