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
    int dfs(TreeNode *node) {
        if (node == nullptr)
            return 0;
        
        return 1 + max(dfs(node->left), dfs(node->right));
    }
    
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};

/*
the height of the binary tree rooted node
    = 1 + max(height of subtreee rooted at node->left,
              height of subtreee rooted at node->right).
    
time complexity: O(n)
space complexity: O(h) where h is the height of the tree

https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/