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

void addNode(Node* &head, int val) {
  if (head == nullptr) {
    head = new Node(val);
  } else {
    Node* newNode = new Node(val);
    Node* curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

int main() {
  Node* head = nullptr;
  while (true) {
    cout << "Options - Add node: 1, Exit: -1\n";
    
    int option;
    cout << "Please chose an option: ";
    cin >> option;

    if (option == -1) {
      cout << "Program exited successfully!!!\n";
      break;
    } else if (option == 1) {
      int val;
      cout << "Enter a value: ";
      cin >> val;
      addNode(head, val);
    } else {
      cout << "Opps!!! Invalid Option.\n";
    }
  }

  return 0;
}