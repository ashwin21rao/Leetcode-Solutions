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
    // merge 2 sorted linked lists
    ListNode *merge(ListNode *head1, ListNode *head2) {
        // dummy node
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            }
            else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (head1 != nullptr) ? head1 : head2;
        return head->next;
    }
    
    // split linked list into 2 halves and return head of second list
    ListNode *splitList(ListNode *head) {
        // find middle node
        ListNode *head1 = head, *head2 = head->next;
        
        while (head2 != nullptr && head2->next != nullptr) {
            head1 = head1->next;
            head2 = head2->next->next;
        }
        
        ListNode *next = head1->next;
        head1->next = nullptr;
        return next;
    }
    
    // sort linked list
    ListNode *sort(ListNode *head) {
        // size of list is greater than 1
        if (head != nullptr && head->next != nullptr) {
            ListNode *mid = splitList(head);
            
            ListNode *new_head1 = sort(head);
            ListNode *new_head2 = sort(mid);
            
            return merge(new_head1, new_head2);
        }
        
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        return sort(head);
    }
};

/*
we perform in-place merge sort on a linked list.

the sorting consists of the following steps:
    - find the middle element (split the list in half).
        - this is done without using the length of the list
        - we use 2 pointers. one pointer moves at double the speed 
          of the second one.
        - when the faster pointer reaches the end of the list,
          the slower pointer is at the middle node.
        - this is the same as the question: 
          https://leetcode.com/problems/middle-of-the-linked-list/
        
    - sort the left half and return the new head.
    - sort the right half and return the new head.
    - merge the 2 sorted linked lists in place.
        - this is the same as the question:
          https://leetcode.com/problems/merge-two-sorted-lists/
        
time complexity: O(n logn)
space complexity: O(1) since we sort in-place.

https://leetcode.com/problems/sort-list/
*/