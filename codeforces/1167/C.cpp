#include <bits/stdc++.h>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)

int findRep(vector<int> &repV, int originRep) {
  while (repV[originRep] != originRep) {
    originRep = repV[originRep];
  }
  return originRep;
}

void join(vector<int> &repV, vector<int> &size, int a, int b) {
  size[a] += size[b];
  repV[b] = a;
}

int main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  int n, m;
  cin >> n >> m;
  vector<int> repV(n + 1);
  for (int i = 1; i <= n; i++) {
    repV[i] = i;
  }
  vector<int> size(n + 1, 1);

  REP(i, 0, m) {
    int count;
    cin >> count;
    vector<int> k(count);
    REP(j, 0, count) {
      cin >> k[j];
    }

    REP(j, 0, count - 1) {
      int repA = findRep(repV, k[j]);
      int repB = findRep(repV, k[j + 1]);
      if (repA == repB) continue;

      if (size[repA] < size[repB]) swap(repA, repB);

      join(repV, size, repA, repB);
    }
  }

  REP(i, 1, n + 1) {
    int rep = findRep(repV, i);
    cout << (i > 1 ? " " : "") << size[rep];
  }
  cout << endl;
}
