#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> v(rooms.size());
    v[0] = true;
    int count = 1;

    queue<int> q;
    q.push(0);
    while (q.size()) {
      int item = q.front();
      q.pop();

      for (auto x : rooms[item]) {
        if (v[x]) continue;
        count++;
        v[x] = true;
        q.push(x);
      }
    }

    return count == rooms.size();
  }
};