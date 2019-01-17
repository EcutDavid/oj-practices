#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)

int a[1000];
int main() {
  int n, l;
  cin >> n >> l;
  REP(i, 0, n)
    cin >> a[i];

  sort(&a[0], &a[n]);
  double rMin = max(a[0], l - a[n-1]);
  REP(i, 0, n-1)
    rMin = max(rMin, (double)(a[i+1] - a[i]) / 2.0);

  printf("%.6f\n", rMin);
}
