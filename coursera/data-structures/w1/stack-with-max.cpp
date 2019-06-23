#include <iostream>
#include <stack>
#include <string>

int main() {
  int n;
  std::cin >> n;

  std::stack<int> s;
  std::stack<int> m;
  for (int i = 0; i < n; i++) {
    std::string type;
    std::cin >> type;
    if (type == "max") {
      std::cout << (m.empty() ? 0 : m.top()) << "\n";
      continue;
    }
    if (type == "pop") {
      if (s.empty()) continue;
      if (s.top() == m.top()) m.pop();
      s.pop();
      continue;
    }
    int num;
    std::cin >> num;
    s.push(num);
    if (m.empty() || m.top() <= num) {
      m.push(num);
    }
  }
}