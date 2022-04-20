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
    // reverse list and return new head
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *node = head;
        
        while (node != nullptr) {
            ListNode *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        
        // find middle node in list
        ListNode *node1 = head, *node2 = head;
        
        while (node2->next != nullptr && node2->next->next != nullptr) {
            node1 = node1->next;
            node2 = node2->next->next;
        }
        ListNode *next = node1->next;
        node1->next = nullptr;
        node1 = next;
        
        // reverse second half of list
        ListNode *head1 = head;
        ListNode *head2 = reverseList(node1);
        
        // merge 2 lists
        // merge list2 into list1
        // length of list 2 <= list1
        while (head2 != nullptr) {
            ListNode *next1 = head1->next;
            ListNode *next2 = head2->next;
            
            head1->next = head2;
            head2->next = next1;
            
            head1 = next1;
            head2 = next2;
        }
    }
};

/*
find the middle node of the list by using 2 pointers:
    - pointer2 moves at double the rate of pointer1

- reverse the second list
- merge the first list and the reversed second list node by node

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/reorder-list/
*/