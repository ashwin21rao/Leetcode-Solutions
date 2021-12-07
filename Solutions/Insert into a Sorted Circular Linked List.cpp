/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    // insert node in between node1 and node2
    void insert(Node *node1, Node *node2, Node *node) {
        node1->next = node;
        node->next = node2;
    }
    
    Node* insert(Node* head, int insertVal) {
        // create new node
        Node *new_node = new Node(insertVal);
        
        if (head == nullptr) {
            // make list circular
            new_node->next = new_node;
            return new_node;
        }
        
        // two pointers
        Node *node1 = head, *node2 = head->next;
        
        while (node2 != head) {
            if (insertVal >= node1->val && insertVal <= node2->val) {
                insert(node1, node2, new_node);
                return head;
            }
            if (node1->val > node2->val) {
                if (insertVal >= node1->val || insertVal <= node2->val) {
                    insert(node1, node2, new_node);
                    return head;
                }
            }
            
            node1 = node1->next;
            node2 = node2->next;
        }
        
        // there is only one position left to insert the new node
        insert(node1, node2, new_node);
        return head;
    }
};

/*
we traverse the linked list using 2 pointers. 
    - node1: current node
    - node2: next node (node1->next)
  
- if node1->val <= insertVal <= node2->val, then we have found the insert position.
- if node1->val > node2->val, then node1 points to the last element in the linked list.
    - if insertVal >= node1->val, it is the largest element in the list.
    - if insertVal <= node2->val, it is the smallest element in the list.
    - in both cases, we insert it between node1 and node2.

- if we traverse the entire linked list without making an insertion, it means
  that all nodes in the list are equal. in this case, we can insert the new node anywhere.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
*/