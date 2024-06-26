#include <iostream>

using namespace std;

class Node {
 public:
  int val;
  Node* next;

  Node(int val) {
    this->val = val;
    this->next = nullptr;
  }
};

void addNode(Node*& head, int val) {
  if (head == nullptr) {
    head = new Node(val);
  } else {
    Node* curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    Node* newNode = new Node(val);
    curr->next = newNode;
  }
}

int main() {
  Node* head = nullptr;

  int val;
  while (cin >> val && val != -1) {
    addNode(head, val);
  }

  for (Node* i = head; i != nullptr; i = i->next) {
    for (Node* j = i->next; j != nullptr; j = j->next) {
      if (i->val < j->val) {
        swap(i->val, j->val);
      }
    }
  }

  Node* curr = head;
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  return 0;
}