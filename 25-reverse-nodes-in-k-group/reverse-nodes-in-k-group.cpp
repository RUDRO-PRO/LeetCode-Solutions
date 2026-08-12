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

        // Step 1: Count the total number of nodes in the linked list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // Create a dummy node to handle head pointer changes cleanly
        ListNode dummy(0, head);
        ListNode* prevGroupEnd = &dummy;
        while (length >= k) {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = groupStart;          
            // Move nextGroupStart to the start of the following group
            for (int i = 0; i < k; i++) {
                nextGroupStart = nextGroupStart->next;
            }

            // Reverse the current k-group
            ListNode* prev = nextGroupStart;
            ListNode* current = groupStart;
            ListNode* next = nullptr;
            for (int i = 0; i < k; i++) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                        }
            // Connect the reversed group back to the main list
            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;   
            // Decrease the remaining length count by k
            length -= k;
        }
        return dummy.next;
    }
};