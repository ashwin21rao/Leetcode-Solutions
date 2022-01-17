/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        // offset (column) -> nodes
        unordered_map<int, vector<int>> nodes;
        
        // max offset on either side
        int left_offset = 0, right_offset = 0;
        
        // node, {level, offset}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            auto [level, offset] = pos;
            q.pop();
            
            if (node == nullptr)
                continue;
            
            nodes[offset].push_back(node->val);
            
            left_offset = min(left_offset, offset);
            right_offset = max(right_offset, offset);
            
            q.push({node->left, {level + 1, offset - 1}});
            q.push({node->right, {level + 1, offset + 1}});
        }
        
        // construct output
        vector<vector<int>> out;
        for (int offset=left_offset; offset<=right_offset; offset++)
            out.push_back(nodes[offset]);
        
        return out;
    }
};

/*
for each node, we maintain:
    - its horizontal offset (to the left or right)
    - its level (depth in the tree)

the output consists of nodes grouped by their offset, in ascending order.
    - within a group, nodes are in ascending order of their level.
    - for nodes at the same level, the left node comes first.

we traverse the tree using BFS.
    - this ensures that top level nodes are added to the output first.
    - for each node, we add the node to the list of nodes with that offset.

implementation:
    - we can maintain a sorted map which maps offset to all nodes with that offset.
    - this ensures that the offsets are stored in ascending order.
    - time complexity: O(nlogn)

time complexity optimization: 
    - we use an unordered map instead.
    - during BFS, we find the minimum and maximum offset of nodes in the tree.
    - we then loop over all offsets in this range and add the corresponding nodes 
      to the output. hence, offsets will be added in ascending order.
    - time complexity: O(n)

time complexity: O(n)
space complexity: O(n)

https://leetcode.com/problems/binary-tree-vertical-order-traversal/
*/