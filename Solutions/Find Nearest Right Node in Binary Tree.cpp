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
    TreeNode *dfs(TreeNode *node, TreeNode *u, int depth, int &u_depth) {
        if (node == nullptr)
            return nullptr;
        
        // target node found
        // return immediately since we do not need to enter subtree
        if (node == u) {
            u_depth = depth;
            return nullptr;
        }
        
        // answer found
        // return immediately since we do not need to enter subtree
        if (depth == u_depth)
            return node;
        
        // recurse
        TreeNode *left_res = dfs(node->left, u, depth + 1, u_depth);
        if (left_res != nullptr)
            return left_res;
        
        return dfs(node->right, u, depth + 1, u_depth);
    }
    
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        int u_depth = -1;
        return dfs(root, u, 0, u_depth);
    }
};

/*
DFS solution:
    - when we encounter the node u, store its depth.
    - in subsequent dfs calls, we do not need to go below this depth.
    - if we reach this depth again, the current node is the asnswer.
    - since we traverse from left to right, the answer will be
      to the right of node u.

time complexity: O(n)
space complexity: O(depth of node u)

https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/
*/