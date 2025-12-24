// reverse node in k group

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* reverseKGroup(ListNode* head, int k) {

        // Step 1: Check if at least k nodes exist
        ListNode* temp = head;
        for(int i = 0; i < k; i++) {
            if(temp == nullptr) return head; // less than k nodes
            temp = temp->next;
        }

        // Step 2: Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        int count = 0;
        while(count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Recursive call for remaining list
        head->next = reverseKGroup(curr, k);

        // Step 4: prev is new head
        return prev;
    }

