#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;

int findSetRep(vector<int>& rep, int n) {
  while (rep[n] != n) {
    n = rep[n];
  }
  return n;
}

void joinSets(vector<int>& rep, vector<int>& size, int x, int y) {
  if (size[y] > size[x]) {
    swap(x, y);
  }
  rep[y] = x;
  size[x] += size[y];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> size(n, 1);
  vector<int> rep(n, 0);
  for (int i = 1; i < n; i++) {
    rep[i] = i;
  }

  int ret = n;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int xRep = findSetRep(rep, x - 1);
    int yRep = findSetRep(rep, y - 1);
    if (xRep == yRep) {
      continue;
    }
    ret--;
    joinSets(rep, size, xRep, yRep);
  }
  cout << ret << "\n";
}