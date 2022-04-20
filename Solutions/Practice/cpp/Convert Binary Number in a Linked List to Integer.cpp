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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head != nullptr) {
            ans <<= 1;
            ans |= head->val;
            head = head->next;
        }
        
        return ans;
    }
};

/*
we use bit manipulation to directly accumulate the answer.

at each node:
    - left shift all bits in the answer to make space for the current node's bit
    - add the current node's bit in the newly created position using bitwise OR.
    
time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
*/