// https://leetcode.com/problems/lru-cache/
#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

typedef list<pair<int, int>> List;

class LRUCache {
 private:
  List l;
  unordered_map<int, List::iterator> m;
  int c;

 public:
  LRUCache(int capacity) {
    c = capacity;
  }

  int get(int key) {
    if (m.count(key) == 0) return -1;
    int ret = m[key]->second;
    l.erase(m[key]);
    l.push_back({key, ret});
    m[key] = --l.end();
    return ret;
  }

  void put(int key, int value) {
    if (m.count(key) == 1) {
      l.erase(m[key]);
    } else if (m.size() == c) {
      auto t = l.begin();
      l.pop_front();
      m.erase(t->first);
    }
    l.push_back({key, value});
    m[key] = --l.end();
  }
};
