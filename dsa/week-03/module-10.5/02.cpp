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

void print(Node* head) {
  Node* curr = head;
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

void reverseList(Node*& head, Node*& tail) {
  Node* i = head;
  Node* j = tail;
  while (i != j && i->next != j) {
    swap(i->val, j->val);
    i = i->next;
    j = j->prev;
  }
}

int main() {
  Node* head = nullptr;
  Node* tail = nullptr;

  int val;
  while (cin >> val && val != -1) {
    insert(head, tail, val);
  }

  reverseList(head, tail);
  print(head);

  return 0;
}