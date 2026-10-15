/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Check if there are at least k nodes left to reverse
        ListNode* cursor = head;
        for (int i = 0; i < k; ++i) {
            if (!cursor) return head; // Less than k nodes, leave as is
            cursor = cursor->next;
        }

        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        for (int i = 0; i < k; ++i) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Recursively reverse the remaining list and connect
        head->next = reverseKGroup(current, k);

        return prev; // prev is the new head of this k-group
    }
};