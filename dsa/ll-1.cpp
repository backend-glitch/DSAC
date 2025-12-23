#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void insertFront(int val) {

    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;

}

  void insertBack(int val) {

    Node* newNode = new Node(val);

    // Case 1: empty list
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Case 2: non-empty list
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteFront(){

     if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head -> next;
    delete temp;
}


void deleteBack() {

    // Case 1: empty list
    if (head == nullptr) {
        cout << "empty\n";
        return;
    }

    // Case 2: only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 3: more than one node
    Node* temp = head;

    // stop at second last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;      // delete last node
    temp->next = nullptr;  // fix link
}




void insertAt(int k, int val) {

    // Case 1: invalid index
    if (k < 0) {
        cout << "Invalid index\n";
        return;
    }

    // Case 2: insert at head
    if (k == 0) {
        insertFront(val);
        return;
    }

    Node* temp = head;
    int count = 0;

    // Move to (k-1)th node
    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }

    // If k is greater than length
    if (temp == nullptr) {
        cout << "Index out of bounds\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}



void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


};

