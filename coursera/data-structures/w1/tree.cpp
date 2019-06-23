#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

struct Node {
  std::vector<Node*> children;
};

int computeTreeHeight(Node* n) {
  if (!n) return 0;
  int ret = 1;
  for (auto d : n->children) {
    ret = std::max(ret, 1 + computeTreeHeight(d));
  }
  return ret;
}

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<int, Node*> m;
  int rootID = -1;
  for (int i = 0; i < n; i++) {
    int parent;
    std::cin >> parent;
    if (parent == -1) rootID = i;

    if (!m.count(i)) m[i] = new Node();
    if (!m.count(parent)) m[parent] = new Node();

    if (parent != -1) {
      m[parent]->children.push_back(m[i]);
    }
  }

  int treeHeight = computeTreeHeight(m[rootID]);
  std::cout << treeHeight << std::endl;
}