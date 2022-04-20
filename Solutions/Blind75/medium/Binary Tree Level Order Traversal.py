# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        
        dq = deque([root])
        out = []
        
        while dq:
            size = len(dq)
            
            # loop over current level
            level = []
            for _ in range(size):
                node = dq.popleft()
                level.append(node.val)
                
                if node.left is not None:
                    dq.append(node.left)
                if node.right is not None:
                    dq.append(node.right)
            
            out.append(level)
        
        return out

"""
- for each level, iterate over the level and add children to the queue.
- in this approach, we do not need to store the level of every node.

time complexity: O(n)
space complexity: O(n)
"""