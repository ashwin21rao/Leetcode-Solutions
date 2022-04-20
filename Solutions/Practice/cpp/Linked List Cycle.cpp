/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        
        ListNode *node1 = head->next;
        ListNode *node2 = head->next->next;
        
        while (node1 != node2) {
            // no cycle
            if (node2 == nullptr || node2->next == nullptr)
                return false;
            
            node1 = node1->next;
            node2 = node2->next->next;
        }
        
        return true;
    }
};

/*
we use FLOYD'S TORTOISE AND HARE to detect a cycle in O(1) space.

we maintain 2 pointers node1 and node2.
    - node2 traverses the linked list twice as fast as node1.
    - node1 is updated as node1 = node1->next.
    - node2 is updated as node2 = node2->next->next.

if the linked list does not have a cycle, the faster pointer
will eventually become null.

if the linked list has a cycle, pointers node1 and node2 will 
eventually meet.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/linked-list-cycle/
*/