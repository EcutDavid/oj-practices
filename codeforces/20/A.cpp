#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  string input;
  cin >> input;
  string output;
  bool prevIsDelimiter = false;
  for (int i = 0; i < input.size(); i++) {
    char c = input[i];
    if (c == '/') {
      if (prevIsDelimiter) continue;
      prevIsDelimiter = true;
    } else {
      prevIsDelimiter = false;
    }
    output.push_back(c);
  }
  if (output.size() > 1 && output[output.size() - 1] == '/') {
    output.erase(output.size() - 1);
  }
  cout << output << endl;
}
