#include <iostream>
using namespace std;


struct SNode {
    int data;
    SNode* next;
};


struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};


void displaySLL(SNode* head) {
    cout << "\nSingly Linked List:\n";
    while (head != NULL) {
        cout << "Data: " << head->data
             << " | Address: " << head
             << " | Next: " << head->next << endl;
        head = head->next;
    }
}


void displayDLL(DNode* head) {
    cout << "\nDoubly Linked List:\n";
    while (head != NULL) {
        cout << "Data: " << head->data
             << " | Address: " << head
             << " | Prev: " << head->prev
             << " | Next: " << head->next << endl;
        head = head->next;
    }
}

void displaySCLL(SNode* head) {
    cout << "\nSingly Circular Linked List:\n";
    SNode* temp = head;
    do {
        cout << "Data: " << temp->data
             << " | Address: " << temp
             << " | Next: " << temp->next << endl;
        temp = temp->next;
    } while (temp != head);
}

void displayDCLL(DNode* head) {
    cout << "\nDoubly Circular Linked List:\n";
    DNode* temp = head;
    do {
        cout << "Data: " << temp->data
             << " | Address: " << temp
             << " | Prev: " << temp->prev
             << " | Next: " << temp->next << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() {

 
    SNode* s1 = new SNode{10, NULL};
    SNode* s2 = new SNode{20, NULL};
    SNode* s3 = new SNode{30, NULL};
    s1->next = s2;
    s2->next = s3;

    displaySLL(s1);

 
    DNode* d1 = new DNode{1, NULL, NULL};
    DNode* d2 = new DNode{2, NULL, NULL};
    DNode* d3 = new DNode{3, NULL, NULL};

    d1->next = d2;
    d2->prev = d1;
    d2->next = d3;
    d3->prev = d2;

    displayDLL(d1);

    SNode* c1 = new SNode{100, NULL};
    SNode* c2 = new SNode{200, NULL};
    SNode* c3 = new SNode{300, NULL};

    c1->next = c2;
    c2->next = c3;
    c3->next = c1;   

    displaySCLL(c1);

   
    DNode* dc1 = new DNode{11, NULL, NULL};
    DNode* dc2 = new DNode{22, NULL, NULL};
    DNode* dc3 = new DNode{33, NULL, NULL};

    dc1->next = dc2;
    dc2->prev = dc1;
    dc2->next = dc3;
    dc3->prev = dc2;

    dc3->next = dc1;  
    dc1->prev = dc3;

    displayDCLL(dc1);

    return 0;
}
