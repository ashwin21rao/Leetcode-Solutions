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
    void findInorder(TreeNode *node, vector<int> &inorder) {
        if (node == nullptr) 
            return;
        
        findInorder(node->left, inorder);
        inorder.push_back(node->val);
        findInorder(node->right, inorder);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        findInorder(root1, arr1);
        findInorder(root2, arr2);
        
        // merge arrays
        vector<int> ans;
        int l1 = arr1.size(), l2 = arr2.size();
        int i = 0, j = 0;
        
        while (i < l1 && j < l2) {
            if (arr1[i] <= arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            }
            else {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while (i < l1) {
            ans.push_back(arr1[i]);
            i++;
        }
        while (j < l2) {
            ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
};

/*
this approach uses 2 passes.

- find the inorder traversal of each binary search tree.
  these will be sorted.
- merge the 2 sorted arrays.

n = number of nodes in BST 1
m = number of nodes in BST 2
time complexity: O(n + m)
space complexity: O(n + m) since we store 2 extra arrays, one for each tree.

https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/