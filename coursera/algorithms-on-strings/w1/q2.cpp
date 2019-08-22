#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

struct TrieNode {
  char c;
  unordered_map<char, TrieNode *> children;
};

int main() {
  string text;
  int n;
  cin >> text >> n;

  auto rootNode = new TrieNode{};

  for (int i = 0; i < n; i++) {
    string word;
    cin >> word;
    auto cur = rootNode;
    for (char c : word) {
      if (cur->children.count(c)) {
        cur = cur->children[c];
      } else {
        auto newNode = new TrieNode{c};
        cur->children[c] = newNode;
        cur = newNode;
      }
    }
  }

  vector<int> indexes;
  for (int i = 0; i < text.size(); i++) {
    auto triePointer = rootNode;
    auto textPointer = i;

    while(triePointer->children.size()) {
      char c = text[textPointer];
      if (triePointer->children.count(c)) {
        textPointer++;
        triePointer = triePointer->children[c];
      } else {
        break;
      }
    }

    if (triePointer->children.empty()) {
      indexes.push_back(i);
    }
  }

  for (int i = 0; i < indexes.size(); i++) {
    cout << (i > 0 ? " " : "") << indexes[i];
  }
}
