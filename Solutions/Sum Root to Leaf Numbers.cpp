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
    void dfs(TreeNode *node, int num_so_far, int &sum) {
        if (node == nullptr) return;
        
        // calculate new number
        int num = num_so_far * 10 + node->val;
        
        // leaf node reached
        if (node->left == nullptr && node->right == nullptr) {
            sum += num;
        }
        else {
            dfs(node->left, num, sum);
            dfs(node->right, num, sum);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};

/*
we pass to each dfs call the number calculated from the nodes before that node.
if we reach a leaf, we add the generated number to the sum.

time complexity: O(n)
space complexity: O(h)

https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/