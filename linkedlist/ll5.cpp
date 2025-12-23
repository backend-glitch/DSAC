// flatten a doubly ll
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};


 Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* next = curr->next;

                // Flatten child
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;

                // Move to tail of child list
                while (curr->next)
                    curr = curr->next;

                // Attach saved next
                curr->next = next;
                if (next)
                    next->prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }