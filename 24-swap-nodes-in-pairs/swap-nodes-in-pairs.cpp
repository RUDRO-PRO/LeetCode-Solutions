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
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        
        // Loop while there are at least two nodes left to swap
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Perform the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev two steps forward (to the end of the swapped pair)
            prev = first;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up memory for the dummy node
        
        return newHead;
    }
};