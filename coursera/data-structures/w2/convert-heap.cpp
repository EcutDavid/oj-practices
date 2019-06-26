#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, int> Swap;

using std::cin;
using std::cout;
using std::swap;
using std::vector;

int calcLeftChild(int index) {
  return index * 2 + 1;
}

int calcRightChild(int index) {
  return index * 2 + 2;
}

int main() {
  int n;
  cin >> n;
  if (n == 1) {  // because it will break the (n - 2) below.
    cout << 0;
    return 0;
  }

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<Swap> s;
  int r = (n - 2) / 2;
  for (int i = r; i >= 0; i--) {
    int index = i;
    while (calcLeftChild(index) < n) {
      int smallest = index;
      int left = calcLeftChild(index);
      if (arr[left] < arr[smallest]) {
        smallest = left;
      }
      int right = calcRightChild(index);
      if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
      }
      if (smallest == index) break;
      s.push_back({index, smallest});
      swap(arr[index], arr[smallest]);

      index = smallest;
    }
  }

  cout << s.size() << "\n";
  for (int i = 0; i < s.size(); i++) {
    cout << s[i].first << " " << s[i].second << "\n";
  }
}