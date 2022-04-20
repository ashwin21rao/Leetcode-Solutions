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
        ListNode *prev = nullptr;
        ListNode *node = head;
        
        while (node != nullptr && node->next != nullptr) {
            ListNode *next = node->next;
            
            node->next = node->next->next;
            next->next = node;
            
            if (prev != nullptr)
                prev->next = next;
            else
                head = next;
            
            prev = node;
            node = node->next;
        }
        
        return head;
    }
};

/*
node = current node (to be swapped with next node)
next = node->next
prev = node->prev

(prev) --> (node) --> (next) --> (node->next->next)

for each swap, change the following connections:
    - node->next = node->next->next
    - next->next = node
    - prev->next = next
    - prev = node

time complexity: O(n)
space complexity: O(1)
*/
