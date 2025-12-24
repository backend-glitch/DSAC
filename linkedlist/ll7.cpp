// swap nodes 


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};


ListNode* swapPairs(ListNode* head) {

        // Dummy node simplifies head swapping
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {

            ListNode* first  = prev->next;
            ListNode* second = first->next;

            // Swapping
            first->next  = second->next;
            second->next = first;
            prev->next   = second;

            // Move prev forward
            prev = first;
        }

        return dummy.next;
    }