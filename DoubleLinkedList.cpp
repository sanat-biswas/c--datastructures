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

  // for inserting the data at a given position
  Node *insertAtPosition(int data, int pos) {

    Node *newNode = new Node(data);

    // if position is 0 or there's no node in the list

    if (head == nullptr || pos == 0) {
      newNode->next = head;

      if (head) {
        head->prev = newNode;
      }

      head = newNode;
      if (!tail) {
        tail = newNode;
      }
      return newNode;
    }
    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp; i++) {
      temp = temp->next;
    }

    // if position not found insert at the end of the list
    if (!temp) {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }

    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next) {
      temp->next->prev = newNode;
    }

    temp->next = newNode;

    return newNode;
  }

  // for deleting the node from the begining of the list
  void deleteFromBegining() {

    if (head == nullptr) {
      return;
    }

    Node *temp = head;
    if (head->next) {
      head = head->next;
      head->prev = nullptr;
    } else {
      head = tail = nullptr;
    }
    delete temp;
  }

  // delete the node from end of the list
  void deleteFromEnd() {

    if (tail == nullptr) {
      return;
    }

    Node *temp = tail;

    if (tail->prev) {
      tail = tail->prev;
      tail->next = nullptr;
    } else {
      head = tail = nullptr;
    }

    delete temp;
  }

  // for deleting the node from a given position
  void deleteFromPosition(int pos) {
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
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

  // dll.insertAtBeginning(20);
  // dll.print();

  // dll.insertAtEnd(60);
  // dll.insertAtEnd(400);

  // dll.insertAtPosition(300, 2);
  // dll.print();

  dll.deleteFromBegining();
  dll.print();

  dll.deleteFromEnd();
  dll.print();

  dll.deleteFromPosition(3);
  dll.print();
  return 0;
}
