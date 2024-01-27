#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *prev;
  Node *next;

  // constructor for node with both data, a reference to the next node and a
  // reference to the previous node
  Node(int data, Node *prev, Node *next) {
    this->data = data;
    this->prev = prev;
    this->next = next;
  }
  Node(int data) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

class DoubleLinkedList {
private:
  Node *head;
  Node *tail;

public:
  DoubleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  // for coverting the array to linked list
  Node *convertArrtoDLL(vector<int> arr) {

    Node *head = new Node(arr[0]);

    Node *prev = head;

    for (int i = 1; i < arr.size(); i++) {
      Node *temp = new Node(arr[i], prev, nullptr);
      prev->next = temp;
      prev = temp;
    }

    return head;
  }

  // for creating a new linked list
  Node *push(int data) {
    Node *newNode = new Node(data);
    if (!head) {
      head = tail = newNode;
    } else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }

    return newNode;
  }

  // for inserting data at the beginnning of the linked list
  Node *insertAtBeginning(int data) {

    Node *newNode = new Node(data);

    if (head == nullptr) {
      head = tail = newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    return newNode;
  }

  // for inserting node at the end of the linked list
  Node *insertAtEnd(int data) {
    Node *newNode = new Node(data);

    // Node *temp = head;

    // O(n) time complexity
    //  while (temp->next != nullptr) {
    //  temp = temp->next;
    // }

    // newNode->prev = temp->next;
    // temp->next = newNode;
    // temp = newNode;
    //
    if (head == nullptr) {
      head = tail = newNode;
    }

    // O(1) time complexity
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    return newNode;
  }
  // for printing the linked list
  void print() {

    Node *temp = head;

    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};
int main() {
  DoubleLinkedList dll;
  vector<int> arr = {1, 2, 3, 4, 5};
  // Node *head = dll.convertArrtoDLL(arr);
  // dll.print(head);

  for (int i = 1; i < 10; i++) {
    dll.push(i);
  }

  dll.print();

  dll.insertAtBeginning(20);
  dll.print();

  dll.insertAtEnd(60);
  dll.insertAtEnd(400);
  dll.print();
  return 0;
}
