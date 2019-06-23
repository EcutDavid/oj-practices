#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Packet {
  int tArrive;
  int tProcess;
  int id;
};

int main() {
  int s, n;
  std::cin >> s >> n;
  std::queue<Packet> tasks;

  for (int i = 0; i < n; i++) {
    int a, p;
    std::cin >> a >> p;
    tasks.push({a, p, i});
  }

  std::queue<Packet> buffer;
  int time = 0;
  std::vector<int> tHandle(n, -1);
  while (!tasks.empty()) {
    if (buffer.empty()) {
      time = std::max(time, tasks.front().tArrive);
      buffer.push(tasks.front());
      tasks.pop();
      continue;
    }

    tHandle[buffer.front().id] = time;
    time += buffer.front().tProcess;
    while (!tasks.empty() && tasks.front().tArrive < time) {
      if (buffer.size() != s) {
        buffer.push(tasks.front());
      }
      tasks.pop();
    }
    buffer.pop();
  }

  while (!buffer.empty()) {
    tHandle[buffer.front().id] = time;
    time += buffer.front().tProcess;
    buffer.pop();
  }

  for (int i = 0; i < n; i++) {
    std::cout << tHandle[i] << "\n";
  }
}