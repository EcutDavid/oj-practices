#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::reverse;
using std::sort;
using std::string;
using std::unordered_map;
using std::vector;

int main() {
  string t;
  cin >> t;
  int width = t.size();

  // Gen the first columm
  vector<char> fc(width);
  for (int i = 0; i < width; i++) {
    fc[i] = t[i];
  }
  sort(fc.begin(), fc.end());
  // cout << string(fc.begin(), fc.end()) << "\n";

  // Constructing a dict that indicates the indexes chars presented, and the mapping
  unordered_map<char, vector<int>> di;
  unordered_map<int, int> rel;
  for (int i = width - 1; i >= 0; i--) {
    di[fc[i]].push_back(i);
  }
  for (int i = 0; i < width; i++) {
    rel[i] = di[t[i]].back();
    di[t[i]].pop_back();
  }

  // Reconstructing the old string from $
  string reversedStr = "";
  int cur = 0;
  for (int i = 0; i < width; i++) {
    reversedStr += fc[cur];

    cur = rel[cur];
  }
  reverse(reversedStr.begin(), reversedStr.end());
  cout << reversedStr << "\n";
}