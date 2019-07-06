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

struct PHash {
  size_t operator()(const pi32& p) const {
    return hash<int>()(p.first) ^ hash<int>()(p.second);
  }
};

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  REP(i, 1, n + 1) {
    bool possible = true;

    // Read the ADJ
    unordered_map<i32, vector<pi32>> adj;
    unordered_map<pi32, i32, PHash> req;
    vector<string> solution;
    i32 vCount, m;
    cin >> vCount >> m;
    REP(j, 0, m) {
      i32 x, y, z;
      cin >> x >> y >> z;
      solution.push_back(to_string(x) + " " + to_string(y) + " " + to_string(z));
      adj[x].push_back({y, z});
      adj[y].push_back({x, z});
      req[{y, x}] = z;
      req[{x, y}] = z;
    }

    // Do dijkstra's algorithm on vertices, if there is a distance shorter than what initially provides, end earlier.
    REP(j, 1, vCount + 1) {
      if (!possible) break;
      unordered_map<int, int> distance = {{j, 0}};
      priority_queue<int> q;
      q.push(j);
      while (!q.empty()) {
        int item = q.top();
        q.pop();
        int dCur = distance[item];
        for (auto d : adj[item]) {
          int newD = d.second + dCur;
          if (distance[d.first] != 0 && distance[d.first] <= newD) continue;
          distance[d.first] = newD;
          if (distance[d.first] < req[{j, d.first}]) {
            possible = false;
            break;
          }
          q.push(d.first);
        }
      }
    }
    cout << "Case #" << i << ": ";
    if (!possible) {
      cout << "Impossible\n";
      continue;
    }
    cout << solution.size() << "\n";
    for (auto d : solution) {
      cout << d << "\n";
    }
  }
}
