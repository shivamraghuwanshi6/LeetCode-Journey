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
private:
    struct CompareNode {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val; // Min-heap based on node values
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> min_heap;
        
        // Push the head of each list into the heap
        for (auto l : lists) {
            if (l != nullptr) {
                min_heap.push(l);
            }
        }
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while (!min_heap.empty()) {
            ListNode* smallest = min_heap.top();
            min_heap.pop();
            
            curr->next = smallest;
            curr = curr->next;
            
            if (smallest->next != nullptr) {
                min_heap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};