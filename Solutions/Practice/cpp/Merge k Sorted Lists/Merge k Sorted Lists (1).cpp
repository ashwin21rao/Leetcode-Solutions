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
    static bool compare(ListNode *node1, ListNode *node2) {
        // condition reversed for min-heap priority queue
        return node1->val > node2->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        // stores nodes in increasing order of their values
        priority_queue<ListNode*, vector<ListNode*>, decltype(&compare)> pq(compare);
        
        // insert first elements into priority queue
        for (auto &list : lists) {
            if (list != nullptr)
                pq.push(list);
        }
        
        // dummy start node
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        
        // merge k sorted lists
        while (!pq.empty()) {
            // pop smallest node
            ListNode *node = pq.top();
            pq.pop();
            
            // add to linked list
            tail->next = node;
            tail = tail->next;
            
            // push next node
            if (node->next != nullptr)
                pq.push(node->next);
        }
        
        return head->next;
    }
};

/*
this approach processes all k lists at once using k pointers.

- we maintain k pointers, one for each list.
- initially, all k pointers are at the beginning of the lists.

- at each iteration, we find the smallest of these k values
  and add it into the answer.
- to find the smallest value, we use a priority queue (min-heap).
    - the head of the priority queue is the smallest of the k pointers.
    - we then increment that pointer and add the next value to the priority
      queue.
- continue until all values have been added to the answer.

N = sum of lengths of all lists
time complexity: O(Nlogk)
space complexity: O(k) since the priority queue never exceeds length k.

https://leetcode.com/problems/merge-k-sorted-lists/
*/