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
    Node* cloneGraph(Node* start) {
        if (start == nullptr) return nullptr;
        
        // node -> clone
        unordered_map<Node*, Node*> new_nodes;
        
        queue<Node*> q;
        q.push(start);
        new_nodes[start] = new Node(start->val, start->neighbors);
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            // loop over neighbours
            for (auto &next : new_nodes[node]->neighbors) {
                // not visited (create clone)
                if (new_nodes.find(next) == new_nodes.end()) {
                    q.push(next);
                    new_nodes[next] = new Node(next->val, next->neighbors);
                }
                
                // replace neighbour with clone
                next = new_nodes[next];
            }
        }
        
        return new_nodes[start];
    }
};

/*
we maintain a hashmap which maps each node to its new (cloned) node.
this is used to check if a node is visited or not.

traverse the graph using BFS.    
    - in each iteration of BFS, we update all neighbours of the clone 
      of the current node to point to their clones.
    - iterate over all neighbours of the clone:
        - if the neighbour is not visited, clone it and push it 
          onto the queue.
        - if the neighbour is not visited, it has already been cloned. 
        - replace the neighbour with its clone (in the neighbours
          list of the current node's clone).

time complexity: O(n + m) (vertices + edges)
space complexity: O(n) to store the hashmap

https://leetcode.com/problems/clone-graph/
*/