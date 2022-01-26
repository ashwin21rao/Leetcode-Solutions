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
    // after this step, s.top() will be the next node in inorder traversal
    void pushLeftChildren(TreeNode *node, stack<TreeNode*> &s) {        
        // push all left children
        while (node != nullptr) {
            s.push(node);
            node = node->left;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> ans;
        
        pushLeftChildren(root1, s1);
        pushLeftChildren(root2, s2);
        
        while (!s1.empty() || !s2.empty()) {           
            // references cannot be reinitialized
            // hence a pointer must be used
            stack<TreeNode*> *s;
            
            if (s1.empty() || s2.empty())
                s = s1.empty() ? &s2 : &s1;
            else
                s = (s1.top()->val <= s2.top()->val) ? &s1 : &s2;
            
            // push smaller node into answer
            TreeNode *node = s->top();
            s->pop();
            ans.push_back(node->val);
            
            // continue inorder traversal of corresponding BST
            pushLeftChildren(node->right, *s);
        }
        
        return ans;
    }
};

/*
we get the required sorted list in a single pass.

- inorder traversal of a BST gives us its nodes in sorted order.
- we inorder traverse each BST simultaneously, and iteratively (using 2 stacks).

- at each instance, the top of each stack gives us the next
  element in the inorder traversal of each BST.
    - if s1.top() <= s2.top(), then we add s1.top() to the answer and continue
      the inorder traversal of s1 to find the next node in the traversal order.
    - else, we add s2.top() to the answer and continue 
      the inorder traversal of s2 to find the next node in the traversal order.
      
n = number of nodes in BST 1
m = number of nodes in BST 2
time complexity: O(n + m)
space complexity: O(h1 + h2) 
    since the max size of each stack is the height of the corresponding BST.

https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/