#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front
#define PRINT(x) cout << #x ": " << (x) << endl;
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10);

class Suffix {
 public:
  bool isEnd;
  unordered_map<char, Suffix*> children;
};

class StreamChecker {
 private:
  Suffix* suffix = new Suffix();
  vector<char> prevQ;

 public:
  StreamChecker(vector<string>& words) {
    for (string w : words) {
      auto cur = suffix;
      for (int i = w.size() - 1; i >= 0; i--) {
        if (!(cur->children)[w[i]]) (cur->children)[w[i]] = new Suffix();
        cur = (cur->children)[w[i]];
        if (i == 0) cur->isEnd = true;
      }
    }
  }

  bool query(char letter) {
    prevQ.push_back(letter);

    auto cur = suffix;
    for (int i = prevQ.size() - 1; i >= 0; i--) {
      char q = prevQ[i];
      cur = cur->children[q];
      if (!cur) return false;
      if (cur->isEnd) return true;
    }

    return false;
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
