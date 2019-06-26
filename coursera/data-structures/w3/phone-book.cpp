#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::string;
using std::unordered_map;

int main() {
  int n;
  cin >> n;
  unordered_map<int, string> book;

  for (int i = 0; i < n; i++) {
    string type;
    int num;
    cin >> type >> num;
    if (type == "del") {
      book.erase(num);
      continue;
    }
    if (type == "find") {
      if (book.count(num)) {
        cout << book[num] << "\n";
      } else {
        cout << "not found\n";
      }
      continue;
    }

    string name;
    cin >> name;
    book[num] = name;
  }
}