#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

struct Bracket {
  int id;
  bool isOpen;
  char c;
};

std::unordered_map<char, char> open = {
    {'{', '}'},
    {'[', ']'},
    {'(', ')'}};

std::unordered_map<char, char> close = {
    {'}', '{'},
    {']', '['},
    {')', '('}};

// Find the wrong closing bracket first, then the openning.
int main() {
  std::string raw;
  std::cin >> raw;

  std::deque<Bracket> b;
  for (int i = 1; i <= raw.size(); i++) {
    char c = raw[i - 1];
    if (!open.count(c) && !close.count(c)) continue;
    if (open.count(c)) {
      b.push_back({i, true, c});
      continue;
    }
    if (!b.empty() && close[c] == b.back().c) {
      b.pop_back();
      continue;
    }
    std::cout << i << std::endl;
    return 0;
  }

  if (!b.empty()) {
    std::cout << b.front().id << std::endl;
    return 0;
  }

  std::cout << "Success" << std::endl;
}