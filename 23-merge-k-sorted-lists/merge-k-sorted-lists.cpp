#include <vector>
#include <queue>

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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap comparator
        }
    };

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;
        
        // Push the head of each non-empty list into the priority queue
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Extract the minimum node, append it to the result, and push its next node
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};