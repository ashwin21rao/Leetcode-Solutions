/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // returns height of node
    int dfs(Node *node, int &diameter) {
        if (node == nullptr) return 0;
        
        // find top 2 maximum heights of child nodes
        vector<int> max_heights(2, 0);
        for (auto &next : node->children) {
            int height = dfs(next, diameter);
            
            if (height > max_heights[1]) {
                max_heights[0] = max_heights[1];
                max_heights[1] = height;
            }
            else if (height > max_heights[0])
                max_heights[0] = height;
        }
        
        diameter = max(diameter, max_heights[0] + max_heights[1]);
        return 1 + max_heights[1];
    }
    
    int diameter(Node* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

/*
- dfs(node) returns the height of that node.
- for each node, we find the heights of the two children with maximum heights.
- the diameter of the tree rooted at this node will be the sum of these maximum heights.
- we calculate this diameter for each node and return the maximum diameter found.

time complexity: O(n)
space complexity: O(h)

https://leetcode.com/problems/diameter-of-n-ary-tree/
*/