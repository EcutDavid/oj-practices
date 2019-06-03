// Time cost: 13 mins
// Typical DPS problem
#include <vector>;

using namespace std;

class Solution {
 private:
  void search(int node, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ret) {
    if (node == (graph.size() - 1)) {
      ret.push_back(path);
      return;
    }
    for (int target : graph[node]) {
      path.push_back(target);
      search(target, graph, path, ret);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> ret;
    vector<int> path = {0};
    search(0, graph, path, ret);
    return ret;
  }
};