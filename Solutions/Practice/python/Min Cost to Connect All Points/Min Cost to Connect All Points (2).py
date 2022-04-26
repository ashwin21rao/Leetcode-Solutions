class DSU:
    def __init__(self, nodes):
        self.nodes = nodes
        self.parent = {node: node for node in self.nodes}
        self.rank = {node: 0 for node in self.nodes}
        
    def findRoot(self, node):
        if node == self.parent[node]:
            return node
        
        self.parent[node] = self.findRoot(self.parent[node])
        return self.parent[node]
    
    def findUnion(self, node1, node2):
        root1 = self.findRoot(node1)
        root2 = self.findRoot(node2)
        
        if root1 == root2:
            return False
        
        if self.rank[root1] < self.rank[root2]:
            self.rank[root1], self.rank[root2] = self.rank[root2], self.rank[root1]
        
        self.parent[root2] = root1
        self.rank[root1] += self.rank[root2]
        
        return True
    
class Solution:
    def distance(self, point1, point2):
        x1, y1 = point1
        x2, y2 = point2
        return abs(x2 - x1) + abs(y2 - y1)
    
    def minSpanningTree(self, points):
        n = len(points)
        dsu = DSU(points)
        
        edges = sorted((self.distance(point1, point2), point1, point2) 
                        for point1 in points for point2 in points if point1 != point2)
        
        cost = 0
        count = 0
        for dist, point1, point2 in edges:
            # MST done
            if count == n - 1:
                break
            
            # add edge
            if dsu.findUnion(point1, point2):
                cost += dist
                count += 1
                
        return cost
        
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        return self.minSpanningTree([tuple(point) for point in points])

"""
MST using Kruskal's algorithm (using DSU)

- Consider the points as nodes in a graph.
- Distance between each point is the weight of the edge
  between them.
- We want the minimum spanning tree (MST) of this graph.

number of edges E = n^2
number of vertices V = n
time complexity: ElogE = O(n^2 log(n^2))
space complexity: O(E) = O(n^2)
"""