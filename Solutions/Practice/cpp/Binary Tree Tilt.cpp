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
    // returns sum of all nodes in subtree rooted at that node
    int dfs(TreeNode *node, int &ans) {
        if (node == nullptr) return 0;
        
        int left_sum = dfs(node->left, ans);
        int right_sum = dfs(node->right, ans);
        
        ans += abs(left_sum - right_sum);
        return left_sum + right_sum + node->val;
    }
    
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

/*
each dfs call returns the sum of all nodes in the subtree rooted at that node.
we accumulate the tilt for each node in ans.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/binary-tree-tilt/
*/