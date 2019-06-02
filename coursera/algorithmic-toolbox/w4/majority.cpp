#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  int n;
  cin >> n;
  unordered_map<int, int> m;
  int target = n / 2 + 1;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    m[num]++;
    if (m[num] == target) {
      cout << 1 << endl;
      return 0;
    }
  }

  cout << 0 << endl;
}