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
    // merge 2 sorted lists in place
    ListNode *mergeSortedLists(ListNode *node1, ListNode *node2) {
        // dummy head
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        
        // merge 2 sorted lists
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val < node2->val) {
                tail->next = node1;
                node1 = node1->next;
            }
            else {
                tail->next = node2;
                node2 = node2->next;
            }
            
            tail = tail->next;
        }
        
        if (node1 == nullptr)
            tail->next = node2;
        else
            tail->next = node1;
        
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        int k = lists.size();        
        int num_lists = k;
        
        // while there are multiple lists remaining
        while (num_lists > 1) {
            // merge lists 2 at a time
            for (int i=0; i<num_lists; i+=2) {
                if (i != num_lists-1)
                    lists[i/2] = mergeSortedLists(lists[i], lists[i+1]);
                else
                    lists[i/2] = lists[i];
            }
            
            // number of lists decreases by half
            num_lists = (num_lists + 1) / 2;
        }
        
        // return merged list
        return lists[0];
    }
};

/*
this approach involves merging 2 sorted lists at a time.
N = sum of lengths of all lists

NAIVE APPROACH:
    - loop over the lists and merge them sequentially. that is, 
      merge lists[i] with the merged list of the previous lists.
    - time complexity: O(Nk)
    - space complexity: O(1)

DIVIDE AND CONQUER:
    - pick lists 2 at a time and merge each pair separately.
    - this will reduce the number of lists by half.
    - continue merging lists 2 at a time till there is only
      one list remaining.

in each iteration:
    - we loop over each element
    - the number of lists decreases by 2.
    - hence, there will be O(log k) iterations each
      with O(N) time complexity.
      
time complexity: O(Nlogk)
space complexity: O(1) since we merge lists in place.

https://leetcode.com/problems/merge-k-sorted-lists/
*/