#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using std::pair;
using std::swap;
using std::vector;

pair<int, int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int k = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
      if (a[j] < x) {
        k++;
        swap(a[k], a[j]);
      }
    }
  }
  swap(a[l], a[k]);
  return {k, j};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  auto p = partition2(a, l, r);

  randomized_quick_sort(a, l, p.first - 1);
  randomized_quick_sort(a, p.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
