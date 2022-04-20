# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValid(self, node, low, high):
        if node is None:
            return True
        
        if not low < node.val < high:
            return False
        
        return self.isValid(node.left, low, node.val) and \
               self.isValid(node.right, node.val, high)
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.isValid(root, -math.inf, math.inf)

"""
- we pass to each node its allowed range of values (low to high).
- if the node's value is not between low and high,
  the BST is invalid.
- when we go left, the node's value is the maximum allowed value
  in the left subtree.
- when we go right, the node's value is the minimum allowed value
  in the right subtree.

time complexity: O(n)
space complexity:
    - O(h) for the recursion stack
    - worst case: O(n)
    - average case: O(log n) if the BST is balanced
"""