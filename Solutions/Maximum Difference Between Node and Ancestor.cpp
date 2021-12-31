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
    void dfs(TreeNode *node, int max_val, int min_val, int &max_diff) {
        if (node == nullptr)
            return;
        
        max_val = max(max_val, node->val);
        min_val = min(min_val, node->val);
        
        // reached leaf node
        if (node->left == nullptr && node->right == nullptr)
            max_diff = max(max_diff, max_val - min_val);
        // recurse
        else {
            dfs(node->left, max_val, min_val, max_diff);
            dfs(node->right, max_val, min_val, max_diff);
        }
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int max_val = root->val, min_val = root->val;
        int max_diff = 0;
        
        dfs(root, max_val, min_val, max_diff);
        return max_diff;
    }
};

/*
the maximum difference in an array = abs(max_val - min_val)
we find the maximum difference for each root-to-leaf path in the tree.

for each node:
    - find the maximum and minimum value from root till that node.
    - when we reach a leaf, abs(max_val - min_val) is the maximum difference
      for that root-to-leaf path.
    - the maxmimum of all differences of each root-to-leaf path is the required answer.
    
time complexity: O(n)
space complexity: O(h)

https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
*/