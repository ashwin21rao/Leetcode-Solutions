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
        ListNode *node = head, *prev = nullptr;
        
        while (node != nullptr && node->next != nullptr) {
            ListNode *next = node->next->next;
            node->next->next = node;
            
            if (prev != nullptr)
                prev->next = node->next;
            else
                head = node->next;
            
            prev = node;
            node->next = next;
            node = next;
        }
        
        return head;
    }
};

/*
node = current node (to be swapped with next node)
next = node->next->next
prev = node->prev

(prev) --> (node) --> (node->next) --> (next)

for each swap, change the following connections:
    - node->next->next = node
    - node->next = next
    - prev->next = node->next
    - prev = node

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/swap-nodes-in-pairs/
*/