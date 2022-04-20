# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = None
    
    # returns True if p or q is found in subtree else False
    def dfs(self, node, p, q):
        if node is None:
            return False
        
        left_found = self.dfs(node.left, p, q)
        right_found = self.dfs(node.right, p, q)
        
        # node found
        if node == p or node == q:
            # node is LCA
            if left_found or right_found:
                self.ans = node
            
            return True
        
        # answer found already
        if self.ans is not None:
            return True
        
        # current node is LCA
        if left_found and right_found:
            self.ans = node
        
        return left_found or right_found
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.dfs(root, p, q)
        return self.ans

"""
traverse the tree using DFS to search for both nodes simultaneously
dfs(node) returns True if p or q is present in this subtree.

Case 1:
  If the current node is p or q and the other node is found
  in the left or right subtree of the current node, then
  the current node is the LCA.

Case 2:
  If p and q are found in the left and right subtree of the current node,
  then the current node is the LCA.

time complexity: O(n) - single pass DFS
space complexity: O(h)
"""