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

class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at front
    void insertFront(int val) {
        Node* newNode = new Node(val);

        // Case 1: empty list
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        // Case 2: non-empty list
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at back
    void insertBack(int val) {
        Node* newNode = new Node(val);

        // Case 1: empty list
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        // Case 2: non-empty list
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Delete from front
    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        // Only one node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
        delete temp;
    }

    // Delete from back
    void deleteBack() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        // Only one node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = head;
    }

    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
};


int main() {
    CircularLinkedList cll;

    cll.insertFront(10);
    cll.insertFront(20);
    cll.insertBack(30);
    cll.insertBack(40);

    cout << "Circular List:\n";
    cll.display();

    cll.deleteFront();
    cout << "After deleteFront:\n";
    cll.display();

    cll.deleteBack();
    cout << "After deleteBack:\n";
    cll.display();

    return 0;
}
