"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def dfs(self, node, clones):
        # if node is visited, return its clone
        if node in clones:
            return clones[node]
        
        # create clone
        clone = Node(node.val)
        clones[node] = clone
        
        # recurse to clone neighbors
        for neighbor in node.neighbors:
            clone.neighbors.append(self.dfs(neighbor, clones))
        
        return clone
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        
        clones = {}
        return self.dfs(node, clones)

"""
traverse the graph using dfs.
for each node, create a clone and return it.
if the node is already visited, return its clone.

time complexity: O(V + E)
space complexity: O(V + E)
"""