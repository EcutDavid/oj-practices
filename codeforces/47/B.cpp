// Thought both side gonna be needed for correctly reason the result,
// but actually, we just need one side.
#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)

int main() {
  map<char, int> m = {};
  REP(i, 0, 3) {
    string line = "";
    cin >> line;
    m[line[line[1] == '>' ? 0 : 2]]++;
  }

  set<int> s = {};
  REP(i, 'A', 'D') {
    s.insert(m[i]);
  }

  if (s.size() != 3) {
    cout << "Impossible" << endl;
    return 0;
  }

  string result(" ", 3);
  REP(i, 0, 3) {
    result[m['A' + i]] = 'A' + i;
  }
  cout << result << endl;
}
