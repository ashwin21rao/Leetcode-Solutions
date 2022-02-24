/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *dfs(Node *node, unordered_map<Node*, Node*> &new_nodes) {
        // clone node
        Node *clone = new Node(node->val, node->neighbors);
        new_nodes[node] = clone;
        
        // loop over children
        for (auto &next : clone->neighbors) {
            // not visited
            if (new_nodes.find(next) == new_nodes.end())
                next = dfs(next, new_nodes);
            else
                next = new_nodes[next];
        }
        
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        // node -> new node
        unordered_map<Node*, Node*> new_nodes;
        
        return dfs(node, new_nodes);
    }
};

/*
we maintain a hashmap which maps each node to its new (cloned) node.
this is used to check if a node is visited or not.

traverse the graph using DFS.
    - clone the current node.
    - we need to update all neihgbours of this clone to point
      to their clones.
    - iterate over all neighbours of the clone:
        - if the neighbour is already visited, it has been cloned. 
          hence, we replace it with its clone (in the neighbours
          list of the current node's clone).
        - else, we recurse to find the clone of the neighbour.

time complexity: O(n + m) (vertices + edges)
space complexity: O(n) to store the hashmap

https://leetcode.com/problems/clone-graph/
*/