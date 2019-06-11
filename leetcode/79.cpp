#include <string>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

typedef pair<int, int> pi32;

class Solution {
 private:
  bool search(vector<vector<char>>& board, pi32 pos, int index, string& word) {
    static const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    if (board[pos.first][pos.second] != word[index]) return false;
    if ((index + 1) == word.size()) return true;
    char cur = board[pos.first][pos.second];
    board[pos.first][pos.second] = '*';

    for (auto dir : dirs) {
      int y = pos.first + dir[0];
      int x = pos.second + dir[1];
      if (y < 0 || x < 0 || y >= board.size() || x >= board[0].size()) {
        continue;
      }
      bool ret = search(board, {y, x}, index + 1, word);
      if (ret) return ret;
    }
    board[pos.first][pos.second] = cur;
    return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || word.empty()) return false;

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        bool ret = search(board, {i, j}, 0, word);
        if (ret) return ret;
      }
    }

    return false;
  }
};