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
  Node* list1 = nullptr;
  Node* list2 = nullptr;

  int val;
  while (cin >> val && val != -1) {
    addNode(list1, val);
  }
  while (cin >> val && val != -1) {
    addNode(list2, val);
  }

  int list1Size = sizeOfList(list1);
  int list2Size = sizeOfList(list2);
  if (list1Size == list2Size) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}