#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> stepCountMemo(n + 1);
  vector<int> prevMemo(n + 1);

  // Three directions: plus 1, multiply 2, multiply 3.
  for (int i = 2; i <= n; i++) {
    stepCountMemo[i] = stepCountMemo[i - 1];
    prevMemo[i] = i - 1;
    if (i % 2 == 0 && stepCountMemo[i / 2] < stepCountMemo[i]) {
      stepCountMemo[i] = stepCountMemo[i / 2];
      prevMemo[i] = i / 2;
    }
    if (i % 3 == 0 && stepCountMemo[i / 3] < stepCountMemo[i]) {
      stepCountMemo[i] = stepCountMemo[i / 3];
      prevMemo[i] = i / 3;
    }
    stepCountMemo[i] += 1;
  }
  cout << stepCountMemo[n] << "\n";

  vector<int> intermediates;
  while (n) {
    intermediates.push_back(n);
    n = prevMemo[n];
  }
  reverse(intermediates.begin(), intermediates.end());
  for (int i = 0; i < intermediates.size(); i++) {
    cout << (i > 0 ? " " : "") << intermediates[i];
  }
  cout << endl;
}