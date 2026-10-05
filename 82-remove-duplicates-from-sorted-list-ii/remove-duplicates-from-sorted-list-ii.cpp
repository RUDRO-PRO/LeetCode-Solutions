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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head) {
            // Check if current node is the start of duplicates
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Link prev to the node after the duplicate sequence
                prev->next = head->next;
            } else {
                // No duplicate for current value, advance prev
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy.next;
    }
};