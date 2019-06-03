#include <iostream>
#include <vector>

using namespace std;

int main() {
  int aC, bC;
  cin >> aC;
  vector<int> a(aC);
  for (int i = 0; i < aC; i++) {
    cin >> a[i];
  }
  cin >> bC;
  vector<int> b(bC);
  for (int i = 0; i < bC; i++) {
    cin >> b[i];
  }

  vector<vector<int>> m(b.size() + 1);
  for (int i = 0; i <= b.size(); i++) {
    m[i] = vector<int>(a.size() + 1);
  }

  for (int i = 1; i <= b.size(); i++) {
    for (int j = 1; j <= a.size(); j++) {
      m[i][j] = m[i - 1][j - 1];
      if (b[i - 1] == a[j - 1]) {
        m[i][j]++;
      }
      m[i][j] = max(m[i][j], m[i - 1][j]);
      m[i][j] = max(m[i][j], m[i][j - 1]);
    }
  }

  cout << m[b.size()][a.size()] << endl;
}