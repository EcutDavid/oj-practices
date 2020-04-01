#include <iosfwd>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::queue;
using std::string;
using std::unordered_map;
using std::vector;

struct TrieNode {
  char c;
  bool isRoot;
  unordered_map<char, TrieNode*> children;
};

void walk(TrieNode* node) {
  while (node->children.size() == 1) {
    if (!node->isRoot) cout << node->c;
    node = node->children.begin()->second;
  }
  if (!node->isRoot) cout << node->c << "\n";
  for (auto d : node->children) walk(d.second);
}

int main() {
  std::ios::sync_with_stdio(false);
  string text;
  cin >> text;

  auto root = new TrieNode{'r', true};
  for (int i = 0; i < text.size(); i++) {
    auto cur = root;
    for (int j = i; j < text.size(); j++) {
      char c = text[j];
      if (cur->children.count(c)) {
        cur = cur->children[c];
      } else {
        auto newNode = new TrieNode{c};
        cur->children[c] = newNode;
        cur = newNode;
      }
    }
  }

  vector<TrieNode*> q;
  q.push_back(root);
  string ret;

  while (q.size()) {
    auto item = q[q.size() - 1];
    q.pop_back();

    if (!item->isRoot) {
      string w(1, item->c);
      while (item->children.size() == 1) {
        item = item->children.begin()->second;
        w += item->c;
      }
      ret += w + "\n";
    }

    for (auto d : item->children) {
      q.push_back(d.second);
    }
  }
  cout << ret;
}