# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.s = []
        self.root = root
        self.initTree()
    
    def initTree(self):
        node = self.root
        
        # go left
        while node is not None:
            self.s.append(node)
            node = node.left
        
        # add dummy node
        node = TreeNode(0)
        self.s.append(node)

    def next(self) -> int:
        # pop current node and go right
        node = self.s.pop()
        node = node.right
        
        # go left
        while node is not None:
            self.s.append(node)
            node = node.left
        
        return self.s[-1].val

    def hasNext(self) -> bool:
        node = self.s[-1]
        
        # node has right child or is not last in the traversal
        return node.right is not None or len(self.s) > 1

"""
traverse the BST using iterative inorder traversal.
we add a dummy node to start before all BST nodes.

- a node has a next node if:
    - it has a right child
    - it has an ancestor greater than it 
      (the stack will contain this ancestor)

time complexity:
    init():    O(h)
    next():    O(1) on average
    hasNext(): O(1)

space complexity: O(h) for the simulated recursion stack.
"""