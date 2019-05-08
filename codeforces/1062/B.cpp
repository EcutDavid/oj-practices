#include <math.h>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long i64;

unordered_set<int> genPrimeSet(int n) {
  unordered_set<int> ret;
  vector<bool> isP(n + 1, true);
  isP[0] = false;
  isP[1] = false;
  for (int i = 2; i <= n; i++) {
    if (!isP[i]) continue;
    ret.insert(i);
    for (int j = i * 2; j <= n; j += i) {
      isP[j] = false;
    }
  }

  return ret;
}

int calcPower(int n, int p) {
  int ret = 0;
  while (n % p == 0) {
    n /= p;
    ret++;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  auto pSet = genPrimeSet(n);
  int num = 1;
  int pMin = n;
  int pMax = 0;
  for (int p : pSet) {
    if (n % p != 0) continue;
    int power = calcPower(n, p);
    pMin = min(pMin, power);
    pMax = max(pMax, power);
    num *= p;
  }

  int times = 0;
  if (n == 1) {
    cout << num << " " << times << endl;
    return 0;
  }

  if (ceil(log2(pMax)) != floor(log2(pMax))) {
    times += 2;
  } else if (pMax != pMin) {
    times++;
  }
  times += floor(log2(pMax));
  cout << num << " " << times << endl;
}