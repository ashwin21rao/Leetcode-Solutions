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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        // head of 2nd linked list
        ListNode *head2 = head->next;
        // tail of 1st linked list
        ListNode *tail = head;
        
        ListNode *node = head;
        bool odd = true;
        while (node->next != nullptr) {
            ListNode *next = node->next;
            node->next = node->next->next;
            
            // update tail of 1st linked list
            if (odd && node->next != nullptr) 
                tail = node->next;
            odd = !odd;
            
            node = next;
        }
                
        // connect tail of 1st linked list to 
        // head of 2nd linked list
        tail->next = head2;
        
        return head;
    }
};

/*
we maintain 2 pointers:
    - tail of 1st linked list
    - head of 2nd linked list

we also maintain a toggle which tells us if the current node
belongs to the odd or even linked list.

we iterate over the linked list as follows:
    - for each node, connect it to node->next->next.
    - if the current node belongs to the odd linked list, update tail.

connect head of 2nd linked list to tail of 1st linked list.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/odd-even-linked-list/
*/