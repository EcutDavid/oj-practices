#include <sys/resource.h>
#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

struct NodeInfo {
  int valMax;
  int valMin;
};

bool IsBinarySearchTree(int index, vector<Node>& nodes, const vector<NodeInfo*>& nodeInfo) {
  if (index == -1) return true;
  Node node = nodes[index];
  if (node.left != -1) {
    if (nodeInfo[node.left]->valMax >= node.key) return false;
  }
  if (node.right != -1) {
    if (nodeInfo[node.right]->valMin < node.key) return false;
  }
  return IsBinarySearchTree(node.left, nodes, nodeInfo) && IsBinarySearchTree(node.right, nodes, nodeInfo);
}

void parseNodeInfo(Node* node, int index, vector<Node>& nodes, vector<NodeInfo*>& info) {
  if (!node) return;
  int valMax = node->key;
  int valMin = node->key;
  if (node->left != -1) {
    if (!info[node->left]) parseNodeInfo(&nodes[node->left], node->left, nodes, info);
    valMax = max(valMax, info[node->left]->valMax);
    valMin = min(valMin, info[node->left]->valMin);
  }
  if (node->right != -1) {
    if (!info[node->right]) parseNodeInfo(&nodes[node->right], node->right, nodes, info);
    valMax = max(valMax, info[node->right]->valMax);
    valMin = min(valMin, info[node->right]->valMin);
  }
  info[index] = new NodeInfo{valMax, valMin};
}

int main() {
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;  // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }

  int nodes;
  cin >> nodes;
  if (nodes == 0) {
    cout << "CORRECT" << endl;
    return 0;
  }

  vector<Node> tree(nodes);
  vector<int> refCount(nodes);
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    if (left != -1) refCount[left]++;
    if (right != -1) refCount[right]++;
    tree[i] = Node(key, left, right);
  }
  int root = -1;
  for (int i = 0; i < nodes; i++) {
    if (refCount[i] == 0) root = i;
  }

  vector<NodeInfo*> nodeInfo(nodes);
  parseNodeInfo(&tree[root], root, tree, nodeInfo);
  if (IsBinarySearchTree(root, tree, nodeInfo)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
