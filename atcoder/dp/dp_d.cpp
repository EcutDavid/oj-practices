#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
typedef long long i64;

i64 getBestV(vector<pair<i64, i64>> &items, int capacity) {
  vector<i64> memo(capacity + 1);
  for (auto item : items) {
    i64 w, v;
    tie(w, v) = item;
    for (int i = capacity; i >= w; i--) {
      memo[i] = max(memo[i], memo[i - w] + v);
    }
  }
  return memo[capacity];
}

int main() {
  int n, cap;
  cin >> n >> cap;
  vector<pair<i64, i64>> items(n);
  for (int i = 0; i < n; i++) {
    i64 w, v;
    cin >> w >> v;
    items[i] = {w, v};
  }
  cout << getBestV(items, cap) << endl;
}
