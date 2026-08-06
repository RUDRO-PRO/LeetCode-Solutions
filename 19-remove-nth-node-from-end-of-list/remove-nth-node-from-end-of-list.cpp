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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases easily (e.g., removing the head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Advance fast pointer by n + 1 steps to create a gap of n nodes
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow is now right before the target node; remove it
        ListNode* target = slow->next;
        slow->next = slow->next->next;
        
        // Free memory to prevent memory leaks in C++
        delete target;
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        
        return newHead;
    }
};