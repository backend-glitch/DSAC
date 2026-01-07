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

class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at front
    void insertFront(int val) {
        Node* newNode = new Node(val);

        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    // Insert at back
    void insertBack(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete from front
    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
    }

    // Delete from back
    void deleteBack() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }

    // Insert at position k (0-based)
    void insertAt(int k, int val) {
        if (k < 0) {
            cout << "Invalid index\n";
            return;
        }

        if (k == 0) {
            insertFront(val);
            return;
        }

        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < k - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Index out of bounds\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display backward
    void displayBackward() {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};


int main() {
    DoublyLinkedList dll;

    dll.insertFront(10);
    dll.insertFront(20);
    dll.insertBack(30);
    dll.insertBack(40);

    cout << "Forward:\n";
    dll.displayForward();

    cout << "Backward:\n";
    dll.displayBackward();

    dll.deleteFront();
    dll.deleteBack();

    cout << "After deletions:\n";
    dll.displayForward();

    dll.insertAt(1, 99);
    cout << "After insertAt(1, 99):\n";
    dll.displayForward();

    return 0;
}
