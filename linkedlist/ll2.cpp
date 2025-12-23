// middle node
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Find Middle Node
ListNode* findMiddle(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps
    }

    return slow;
}

// Print List
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {

    // Create list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);

    ListNode* middle = findMiddle(head);

    if (middle != nullptr)
        cout << "Middle Node Value: " << middle->val << endl;

    return 0;
}
