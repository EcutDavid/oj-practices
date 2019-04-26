#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  string genKey(string str) {
    sort(str.begin(), str.end());
    return str;
  }

 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ret;
    unordered_map<string, int> m;
    int counter = 0;
    for (auto str : strs) {
      string key = genKey(str);
      if (m.find(key) == m.end()) {
        m[key] = counter++;
        ret.push_back(vector<string>());
      }
      ret[m[key]].push_back(str);
    }

    return ret;
  }
};