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
    // return {min value in tree, max value in tree, size of BST}
    vector<int> dfs(TreeNode *node, int &max_size) {
        // nullptr is BST of size 0
        if (node == nullptr)
            return {INT_MAX, INT_MIN, 0};

        // recurse
        auto left_res = dfs(node->left, max_size);
        auto right_res = dfs(node->right, max_size);

        // child is not BST
        if (left_res[2] == -1 || right_res[2] == -1)
            return {0, 0, -1};

        // node is a BST
        if (node->val > left_res[1] && node->val < right_res[0]) {
            int size = 1 + left_res[2] + right_res[2];

            // new largest BST found
            if (size > max_size)
                max_size = size;

            return {min(left_res[0], node->val), max(right_res[1], node->val), size};
        }

        // node is not a BST
        return {0, 0, -1};
    }
    
    int largestBSTSubtree(TreeNode* root) {
         // size of largest BST
        int max_size = 0;
        
        dfs(root, max_size);
        return max_size;
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