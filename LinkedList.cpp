#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        this->head = nullptr;
    }

    // for inserting the data at the beginning of the linked list
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // for printing the linked list
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    /**
     * for inserting the list at the end of the list
     */
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    /**
     * push the element at the start of the list
     */
    void push(int data)
    {
        Node *new_node = new Node(data);
        new_node->next = head;

        head = new_node;
    }

    /**
     * insert the data at a given position
     */
    void insertAtPosition(int data, int pos)
    {
        Node *newNode = new Node(data);
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;

        for (int i = 0; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        newNode->next = curr;
        prev->next = newNode;
    }

    /**
     * for searching the element in the linked list
     */
    bool search(int x)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    /**
     * for counting the number of elements in the linked list
     */
    int getCount()
    {
        int count = 0;
        Node *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    /**
     * for reversing the linked list
     */
    void reverse()
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    /**
     * for deleting the linked from the beginning
     */
    void deleteFromBeginning()
    {
        Node *temp = head;

        head = head->next;

        delete temp;
    }

    /**
     * for deleting the node from the end
     */
    void deleteFromEnd()
    {
        Node *temp = head;

        Node *prev = nullptr;

        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = nullptr;

        delete temp;
    }

    /**
     * delete the node from a given position
    */
    void deleteFromPosition(int pos)
    {
        Node *temp = head;
        Node *prev = head;

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        prev->next = temp->next;

        delete temp;
    }
};

int main()
{
    LinkedList list;
    Node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        list.insertAtBeginning(i);
    }

    // list.insertAtEnd(20);
    // list.push(100);
    // list.push(200);

    // list.insertAtPosition(300, 4);

    // list.search(300);

    list.printList();

    // cout << "Reverse linked list " << endl;
    // list.reverse();

    cout << "After deleting: " << endl;
    // list.deleteFromEnd();

    list.deleteFromPosition(2);
    list.printList();

    cout << "count " << list.getCount();
}