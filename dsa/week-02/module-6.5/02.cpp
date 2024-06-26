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

Node* reverseList(Node* head) {
  Node* curr = head;
  Node* prev = nullptr;
  Node* next;
  while (curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int main() {
  Node* head = nullptr;

  int val;
  while (cin >> val && val != -1) {
    addNode(head, val);
  }

  Node* revList = reverseList(head);
  while (revList != nullptr) {
    cout << revList->val << " ";
    revList = revList->next;
  }
  cout << endl;

  return 0;
}