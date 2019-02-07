#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

const string target = "the quick brown fox jumps over the lazy dog";

// This part is what the task is really testing.
map<char, char> parseDict(string line) {
  map<char, char> usage, dict;
  REP(i, 0, line.size()) {
    char bound = usage[target[i]];
    if ((line[i] == ' ' && target[i] != ' ') || (bound && (bound != line[i]))) {
      return map<char, char>();
      break;
    }
    if (line[i] == ' ') continue;

    if (dict[line[i]] == 0) dict[line[i]] = target[i];
  }
  return dict;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  string line;
  getline(cin, line);  // To get the line after "n"
  getline(cin, line);  // To get the empty line right after the line "n" belongs to.

  REP(i, 0, n) {
    if (i > 0) cout << "\n";
    map<char, char> dict;
    vector<string> lines;

    while (true) {
      getline(cin, line);
      if (!cin || line == "") {
        if (dict.size() != 26) {
          cout << "No solution.\n";
          break;
        }
        dict[' '] = ' ';
        TR(lines, l) {
          TR(*l, i) {
            cout << dict[*i];
          }
          cout << "\n";
        }
        break;
        lines = {};
      } else {
        lines.PB(line);
        if (line.size() != target.size() || dict.size() == 26) continue;

        dict = parseDict(line);
      }
    }
  }
}
