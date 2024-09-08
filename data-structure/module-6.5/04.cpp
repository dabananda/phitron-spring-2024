#include <bits/stdc++.h>

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

  int maxValue = INT_MIN;
  Node* curr = head;
  while (curr != nullptr) {
    if (curr->val > maxValue) {
      maxValue = curr->val;
    }
    curr = curr->next;
  }
  cout << maxValue << endl;

  return 0;
}