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
    ListNode* middleNode(ListNode* head) {
        ListNode *node1 = head, *node2 = head;
        
        while (node2 != nullptr && node2->next != nullptr) {
            node1 = node1->next;
            node2 = node2->next->next;
        }
        
        return node1;
    }
};

/*
we need to find the middle node of the linked list.

we maintain 2 pointers:
    - the second pointer travels at twice the speed of the first pointer.
    - the first pointer moves one node forward in each step.
    - the second pointer moves two nodes forward in each step.
    
when the second pointer reaches the end of the list, the first
pointer points to the middle node in the list.

time complexity: O(n/2) = O(n)
space complexity: O(1)

https://leetcode.com/problems/middle-of-the-linked-list/
*/