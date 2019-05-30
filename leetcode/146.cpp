// https://leetcode.com/problems/lru-cache/
#include <unordered_map>
#include <utility>

using namespace std;

struct LinkedListNode {
  LinkedListNode *prev;
  LinkedListNode *next;
  pair<int, int> val;
  LinkedListNode(pair<int, int> val) {
    this->val = val;
    prev = nullptr;
    next = nullptr;
  }
};

class DoublyLinkedList {
 private:
  LinkedListNode *head = nullptr;
  LinkedListNode *tail = nullptr;

 public:
  void append(pair<int, int> val) {
    LinkedListNode *newNode = new LinkedListNode(val);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = tail->next;
    }
  }

  void remove(LinkedListNode *node) {
    if (head == tail) {
      head = nullptr;
      tail = nullptr;
      return;
    }
    if (node == head) {
      LinkedListNode *newHead = head->next;
      newHead->prev = nullptr;
      head->next = nullptr;
      head = newHead;
      return;
    }
    if (node == tail) {
      LinkedListNode *newTail = tail->prev;
      tail->prev = nullptr;
      newTail->next = nullptr;
      tail = newTail;
      return;
    }
    LinkedListNode *prev = node->prev;
    LinkedListNode *next = node->next;
    prev->next = next;
    next->prev = prev;
    node->prev = nullptr;
    node->next = nullptr;
  }

  void popHead() {
    remove(head);
  }

  LinkedListNode *getTail() {
    return tail;
  }

  LinkedListNode *getHead() {
    return head;
  }
};

class LRUCache {
 private:
  DoublyLinkedList l;
  unordered_map<int, LinkedListNode *> m;
  int c;

 public:
  LRUCache(int capacity) {
    c = capacity;
  }

  int get(int key) {
    if (m.count(key) == 0) return -1;
    int ret = m[key]->val.second;
    l.remove(m[key]);
    l.append({key, ret});
    m[key] = l.getTail();
    return ret;
  }

  void put(int key, int value) {
    if (m.count(key) == 1) {
      l.remove(m[key]);
    } else if (m.size() == c) {
      auto t = l.getHead();
      l.popHead();
      m.erase(t->val.first);
    }
    l.append({key, value});
    m[key] = l.getTail();
  }
};
