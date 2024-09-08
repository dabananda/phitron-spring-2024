#include <iostream>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* prev;

  Node(int val) {
    this->val = val;
    next = nullptr;
    prev = nullptr;
  }
};

void insert(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node(val);
  if (head == nullptr) {
    head = newNode;
    tail = head;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

bool isPalindrome(Node*& head, Node*& tail) {
  Node* i = head;
  Node* j = tail;
  while (i != j) {
    if (i->val != j->val) {
      return false;
    }
    i = i->next;
    j = j->prev;
  }
  return true;
}

int main() {
  Node* head = nullptr;
  Node* tail = nullptr;

  int val;
  while (cin >> val && val != -1) {
    insert(head, tail, val);
  }

  if (isPalindrome(head, tail)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}