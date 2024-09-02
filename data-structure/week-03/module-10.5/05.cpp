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

void sortList(Node*& head) {
  for (Node* i = head; i != nullptr; i = i->next) {
    for (Node* j = i->next; j != nullptr; j = j->next) {
      if(i->val > j->val) {
        swap(i->val, j->val);
      }
    }
  }
}

int main() {
  Node* head = nullptr;
  Node* tail = nullptr;
  
  int val;
  while (cin >> val && val != -1) {
    insert(head, tail, val);
  }

  sortList(head);
  print(head);

  return 0;
}
