#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::string;
using std::vector;

int main() {
  string t;
  cin >> t;
  int width = t.size();
  vector<string> tv(width);

  for (int i = 0; i < width; i++) {
    tv[i] = t.substr(width - i, i) + t.substr(0, width - i);
  }
  sort(tv.begin(), tv.end());
  for (int i = 0; i < width; i++) {
    cout << tv[i][width - 1];
  }
  cout << "\n";
}