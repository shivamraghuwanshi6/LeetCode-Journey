class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move prev pointer 2 nodes forward
            prev = first;
        }

        return dummy.next;
    }
};