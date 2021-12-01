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
    class NodeInfo {
    public:
        int minVal;
        int maxVal;
        int size;
        
        NodeInfo(int minVal, int maxVal, int size) 
            : minVal(minVal), maxVal(maxVal), size(size) {
        }
    };
    
    // {min value in tree, max value in tree}, size of subtree
    NodeInfo *dfs(TreeNode *node, int &ans) {
        if (node == nullptr)
            return new NodeInfo(1e9, -1e9, 0);
        
        // leaf node
        if (node->left == nullptr && node->right == nullptr)
            return new NodeInfo(node->val, node->val, 1);
        
        auto left_res = dfs(node->left, ans);
        auto right_res = dfs(node->right, ans);
        
        // if tree rooted at node is a BST
        if (node->val > left_res->maxVal && node->val < right_res->minVal) {
            int size = 1 + left_res->size + right_res->size;
            ans = max(ans, size);
            
            return new NodeInfo(node->left == nullptr ? node->val : left_res->minVal, 
                                node->right == nullptr ? node->val : right_res->maxVal, 
                                size);
        }
        
        return new NodeInfo(-1e9, 1e9, 0);
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int ans = 1;
        dfs(root, ans);
        return ans;
    }
};

/*
this question is similar to BST validation.
    - here, we need to validate if each subtree is a BST.
    - so, we use the bottom-up (recursive) method of BST validation.
    
each dfs call returns:
    - the minimum and maximum values in the tree rooted at that node
      (used for BST validation).
    - size of the tree rooted at that node.

the current node is a BST if:
    - its left and right children are BSTs
    - it satisfies the BST property

if the current node is a BST, we compare its size to the maximum size seen so far.

time complexity: O(n)
space complexity: O(h)

https://leetcode.com/problems/largest-bst-subtree/
*/