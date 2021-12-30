/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        Node *start = root;
        
        // loop over each level of binary tree
        while (start->left != nullptr) {
            Node *node = start;
            
            // loop over each node in that level
            while (node != nullptr) {
                // make next pointer connections in below level
                node->left->next = node->right;
                if (node->next != nullptr)
                    node->right->next = node->next->left;
                
                node = node->next;
            }
            
            // go to next level
            start = start->left;
        }
        
        return root;
    }
};

/*
this solution assumes that the given tree is a PERFECT BINARY TREE.

- for each level, we iterate over all nodes in that level using the
  populated next pointers.
- while traversing the current level, we populate the next pointers of the level
  below it.
- hence, when we go to the next level, its next pointers are already populated
  and we use them to traverse that level.
- continue this process until we reach the last level of the binary tree.

- for each level:
    - iterate over all nodes in that level using the already populated next pointers.
    - make next pointer connections of the below level as follows:
        - connect node->left to node->right
        - connect node->right to next_node->left (if next_node is not null)

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/