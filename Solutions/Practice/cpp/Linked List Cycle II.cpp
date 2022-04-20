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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        
        ListNode *node1 = head->next;
        ListNode *node2 = head->next->next;
        
        while (node1 != node2) {
            // no cycle
            if (node2 == nullptr || node2->next == nullptr)
                return nullptr;
            
            node1 = node1->next;
            node2 = node2->next->next;
        }
        
        // find head of cycle
        while (head != node1) {
            head = head->next;
            node1 = node1->next;
        }
        
        return head;
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
the distance of this meeting point from the start node of the cycle
and the distance of the head of the linked list from the start node
of the cycle are equal.
    - so, we traverse the linked list from these 2 positions.
    - the node where these 2 pointers meet is the start of the cycle.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/linked-list-cycle-ii/
*/