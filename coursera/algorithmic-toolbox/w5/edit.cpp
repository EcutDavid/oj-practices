#include <iostream>
#include <vector>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  vector<vector<int>> m(b.size() + 1);
  for (int i = 0; i <= b.size(); i++) {
    m[i] = vector<int>(a.size() + 1);
    m[i][0] = i;
  }
  for (int i = 1; i <= a.size(); i++) {
    m[0][i] = i;
  }
  for (int i = 1; i <= b.size(); i++) {
    for (int j = 1; j <= a.size(); j++) {
      m[i][j] = m[i - 1][j - 1];
      if (b[i - 1] == a[j - 1]) {
        m[i][j]--;
      }
      m[i][j] = min(m[i][j], m[i - 1][j]);
      m[i][j] = min(m[i][j], m[i][j - 1]);
      m[i][j]++;
    }
  }

  cout << m[b.size()][a.size()] << endl;
}