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
    Node* newNode = new Node(val);
    Node* curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = newNode;
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

void deleteHead(Node*& head) {
  Node* temp = head;
  head = head->next;
  delete temp;
}

void deleteByPosition(Node*& head, int pos) {
  if (pos == 1) {
    deleteHead(head);
  } else {
    Node* curr = head;
    for (int i = 1; i < pos - 1; i++) {
      curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
  }
}

int main() {
  Node* head = nullptr;
  while (true) {
    cout << "Options - Add node: 1, Print List: 2, Delete by position: 3, Exit: -1\n";

    int option;
    cout << "Enter an option: ";
    cin >> option;

    if (option == -1) {
      cout << "Program exited successfully !!!\n";
      break;
    } else if (option == 1) {
      int val;
      cout << "Enter a value: ";
      cin >> val;
      addNode(head, val);
    } else if (option == 2) {
      cout << "LinkedList: ";
      print(head);
    } else if (option == 3) {
      int pos;
      cout << "Enter position to delete: ";
      cin >> pos;
      deleteByPosition(head, pos);
      cout << "Node at " << pos << " deleted successfully !!!\n";
    } else {
      cout << "Opps !!! Invalid Option.\n";
    }
  }

  return 0;
}