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

int sizeOfList(Node* head) {
  int count = 0;
  Node* curr = head;
  while (curr != nullptr) {
    count++;
    curr = curr->next;
  }
  return count;
}

int main() {
  Node* head = nullptr;

  int val;
  while (cin >> val && val != -1) {
    addNode(head, val);
  }

  int listSize = sizeOfList(head);

  Node* curr = head;
  int a = 1, b = listSize / 2;
  while (a != b) {
    a++;
    curr = curr->next;
  }
  if (listSize % 2 != 0) {
    cout << curr->next->val << endl;
  } else {
    cout << curr->val << " " << curr->next->val << endl;
  }

  return 0;
}