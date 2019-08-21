#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::string;
using std::unordered_map;

struct TrieNode {
  int id;
  char c;
  unordered_map<char, TrieNode *> children;
};

int main() {
  int n;
  cin >> n;

  int counter = 0;
  auto rootNode = new TrieNode{counter++};

  for (int i = 0; i < n; i++) {
    string word;
    cin >> word;
    auto cur = rootNode;
    for (char c : word) {
      if (cur->children.count(c)) {
        cur = cur->children[c];
      } else {
        auto newNode = new TrieNode{counter++, c};
        // 0->1:A
        cout << cur->id << "->" << newNode->id << ":" << newNode->c << "\n";

        cur->children[c] = newNode;
        cur = newNode;
      }
    }
  }
}