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
#define PRINT(x) cout << #x ": " << (x) << endl;
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10);

typedef pair<double, double> Slot;

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    cout << "Case #" << t << ": ";

    i32 d, s;
    cin >> d >> s;

    vector<pair<double, Slot>> slots;
    REP(i, 0, s) {
      double c, e;
      cin >> c >> e;
      double factor = c / (c + e);
      Slot ce = {c, e};
      slots.push_back({ factor, ce });
    }
    sort(slots.rbegin(), slots.rend());

    REP(i, 0, d) {
      double codeGoal, eatGoal;
      cin >> codeGoal >> eatGoal;

      double fac = 0;
      int index = 0;
      while (codeGoal > 0 && index < s) {
        double power = slots[index].second.first;
        if (codeGoal >= power) {
          codeGoal -= power;
          index++;
        } else {
          fac = codeGoal / power;
          codeGoal = 0;
        }
      }

      if (fac != 0) {
        eatGoal -= (1.0 - fac) * slots[index].second.second;
        index++;
      }

      while(eatGoal > 0 && index < s) {
        eatGoal -= slots[index].second.second;
        index++;
      }

      if (codeGoal <= 0 && eatGoal <= 0) cout << "Y";
      else cout << "N";
    }

    cout << "\n";
  }
}
