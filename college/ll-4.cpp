#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    // Insert at front
    void insertFront(int val) {
        Node* newNode = new Node(val);

        // Case 1: empty list
        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    // Insert at back
    void insertBack(int val) {
        Node* newNode = new Node(val);

        // Case 1: empty list
        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
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
        Node* last = head->prev;

        head = head->next;
        head->prev = last;
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

        Node* last = head->prev;
        Node* secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;

        delete last;
    }

    // Display forward
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }

    // Display backward
    void displayBackward() {
        if (head == nullptr) return;

        Node* temp = head->prev;
        Node* last = temp;

        do {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        } while (temp != last);

        cout << "(back to tail)\n";
    }
};


int main() {
    CircularDoublyLinkedList cdll;

    cdll.insertFront(10);
    cdll.insertFront(20);
    cdll.insertBack(30);
    cdll.insertBack(40);

    cout << "Forward traversal:\n";
    cdll.displayForward();

    cout << "Backward traversal:\n";
    cdll.displayBackward();

    cdll.deleteFront();
    cdll.deleteBack();

    cout << "After deletions:\n";
    cdll.displayForward();

    return 0;
}
