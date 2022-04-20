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
    int dfs(TreeNode *node, int num) {
        if (node == nullptr)
            return 0;
        
        int next_num = (num << 1) | node->val;
        
        // leaf node reached
        if (node->left == nullptr && node->right == nullptr)
            return next_num;
        
        return dfs(node->left, next_num) + dfs(node->right, next_num);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

/*
we pass to each node the number represented by the path so far.
when we reach a leaf node, we add the generated number to the sum.

if the binary number upto the current node and exlcuding it is num:
    - we get the new binary number by adding node->val to the right
      of the bit representation of num.
    - so, we left shift num by 1 and bitwise OR it with node->val.
    - this adds node->val as the rightmost bit.
    
time complexity: O(n)
space complexity: O(h)

https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
*/