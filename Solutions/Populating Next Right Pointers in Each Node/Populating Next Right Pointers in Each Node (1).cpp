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
        Node *prev_node = nullptr;
        int prev_level = -1;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            
            // skip nullptr
            if (node == nullptr)
                continue;
            
            if (level == prev_level)
                prev_node->next = node;
            
            prev_node = node;
            prev_level = level;
            
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        
        return root;
    }
};

/*
this approach works irrespective of the type of tree:
    - complete/incomplete binary tree
    - n-ary tree

traverse the tree using BFS.
maintain a queue in which stores the nodes and their levels in the tree.

- if the current node and previous node have the same level, 
  connect the next pointer of the previous node to the current node.
- else, the previous node is the last node in its level. 
  hence we do not update its next pointer.

time complexity: O(n)
space complexity: O(n)

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/