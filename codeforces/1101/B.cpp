#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back

char open = '[', close = ']', colon = ':', vert = '|';

int main() {
  string str;
  cin >> str; i32 n = str.size();

  i32 openIndex = -1, closeIndex = -1, firstColon = -1, lastColon = -1;
  REP(i, 0, n) {
    if (str[i] == open) {
      openIndex = i;
      break;
    }
  }
  REP(i, 0, n) {
    if (str[n - i - 1] == close) {
      closeIndex = n - i - 1;
      break;
    }
  }
  if ((closeIndex == -1) || (openIndex == -1)) {
    cout << -1 << endl;
    return 0;
  }

  REP(i, openIndex + 1, closeIndex) {
    if (str[i] == colon) {
      firstColon = i;
      break;
    }
  }
  REP(i, firstColon + 1, closeIndex)
    if (str[i] == colon) lastColon = i;
  if ((firstColon == -1) || (lastColon == -1)) {
    cout << -1 << endl;
    return 0;
  }

  i32 vertCount = 0;
  REP(i, firstColon + 1, lastColon)
    if (str[i] == vert) vertCount++;

  cout << vertCount + 4 << endl;
}
