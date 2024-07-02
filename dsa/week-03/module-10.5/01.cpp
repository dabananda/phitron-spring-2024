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

void printReverse(Node* tail) {
  Node* curr = tail;
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->prev;
  }
  cout << endl;
}

int getSize(Node* head) {
  int ans = 0;
  Node* curr = head;
  while (curr != nullptr) {
    curr = curr->next;
    ans++;
  }
  return ans;
}

bool isUnique(Node* headA, Node* headB) {
  bool ans = true;
  Node* currA = headA;
  Node* currB = headB;
  while (currA != nullptr) {
    if (currA->val != currB->val) {
      ans = false;
      break;
    }
    currA = currA->next;
    currB = currB->next;
  }
  return ans;
}

int main() {
  Node* headA = nullptr;
  Node* tailA = nullptr;
  Node* headB = nullptr;
  Node* tailB = nullptr;

  int val;
  while (cin >> val && val != -1) {
    insert(headA, tailA, val);
  }
  while (cin >> val && val != -1) {
    insert(headB, tailB, val);
  }

  int aSize = getSize(headA);
  int bSize = getSize(headB);
  if (aSize != bSize) {
    cout << "NO" << endl;
  } else {
    if (isUnique(headA, headB)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}