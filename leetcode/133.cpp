// Using DFS to solve this problem would cost less lines of code, without the need for using pair, queue, and set.
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::pair;
using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {}

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return node;
    Node* ret = new Node(node->val, vector<Node*>());

    unordered_set<Node*> visited = {node};
    unordered_map<Node*, Node*> m = {{node, ret}};
    queue<pair<Node*, Node*>> q;
    q.push({node, ret});

    while (!q.empty()) {
      Node* origin;
      Node* target;
      tie(origin, target) = q.front();
      q.pop();
      for (auto d : origin->neighbors) {
        if (m.count(d) == 0) {
          m[d] = new Node(d->val, vector<Node*>());
        }
        target->neighbors.push_back(m[d]);
      }
      for (int i = 0; i < origin->neighbors.size(); i++) {
        if (visited.count(origin->neighbors[i])) continue;
        visited.insert(origin->neighbors[i]);
        q.push({origin->neighbors[i], target->neighbors[i]});
      }
    }

    return ret;
  }
};