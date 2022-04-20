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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // dummy head
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        
        // merge 2 sorted lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            
            tail = tail->next;
        }
        
        if (list1 == nullptr)
            tail->next = list2;
        else
            tail->next = list1;
        
        return head->next;
    }
};

/*
- maintain 2 pointers, one for each list.
- we merge the 2 lists in place by starting with a dummy head
  and adding to the tail of this list.
  
time complexity: O(n + m)
space complexity: O(1)

https://leetcode.com/problems/merge-two-sorted-lists/
*/