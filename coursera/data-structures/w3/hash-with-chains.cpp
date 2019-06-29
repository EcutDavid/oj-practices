#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::find;
using std::list;
using std::string;
using std::vector;

typedef long long i64;

class HashTable {
 private:
  vector<list<string>> table;

  int hash(string str) {
    i64 p = 1000000007;
    int x = 263;

    i64 s = 0;
    i64 mul = 1;
    for (int i = 0; i < str.size(); i++) {
      if (i > 0) {
        mul = mul * x % p;
      }
      s += mul * str[i] % p;
    }

    return s  % p % table.size();
  }

 public:
  HashTable(int m) {
    table = vector<list<string>>(m);
  }

  void add(string str) {
    if (find(str)) return;
    int index = hash(str);
    table[index].push_front(str);
  }

  void erase(string str) {
    int index = hash(str);
    auto it = std::find(table[index].begin(), table[index].end(), str);
    if (it == table[index].end()) return;
    table[index].erase(it);
  }

  bool find(string str) {
    int index = hash(str);
    return std::find(table[index].begin(), table[index].end(), str) != table[index].end();
  }

  vector<string> check(int index) {
    return vector<string>(table[index].begin(), table[index].end());
  }
};

// The problem ask us to implementing hashtable via hash-with-chains ourselves,
// which is why not using hashtable from std here.
int main() {
  int m;
  int n;
  cin >> m >> n;
  HashTable t(m);
  for (int i = 0; i < n; i++) {
    string type;
    cin >> type;
    if (type == "check") {
      int index;
      cin >> index;
      auto ls = t.check(index);
      for (int i = 0; i < ls.size(); i++) {
        cout << (i > 0 ? " " : "") << ls[i];
      }

      cout << "\n";
      continue;
    }
    string str;
    cin >> str;
    if (type == "add") {
      t.add(str);
      continue;
    }
    if (type == "del") {
      t.erase(str);
      continue;
    }
    auto ret = t.find(str);
    cout << (ret ? "yes" : "no") << "\n";
  }
}