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
    TreeNode *buildTree(int lb, int ub, int &idx, 
                        unordered_map<int, int> &inorder_indices, vector<int> &postorder) {
        
        if (lb > ub) return nullptr;
        
        TreeNode *node = new TreeNode(postorder[idx]);        
        idx++;
        
        int mid = inorder_indices[node->val];
        node->right = buildTree(mid + 1, ub, idx, inorder_indices, postorder);
        node->left = buildTree(lb, mid - 1, idx, inorder_indices, postorder);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        reverse(postorder.begin(), postorder.end());
        
        // node -> index in inorder traversal array
        unordered_map<int, int> inorder_indices;
        for (int i=0; i<n; i++)
            inorder_indices[inorder[i]] = i;
        
        int idx = 0;
        return buildTree(0, n-1, idx, inorder_indices, postorder);
    }
};

/*
time complexity: O(n)
space complexity: O(n)

https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/