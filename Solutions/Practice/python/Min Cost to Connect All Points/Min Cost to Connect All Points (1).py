class Solution:
    def distance(self, point1, point2):
        return abs(point2[0] - point1[0]) + abs(point2[1] - point1[1])
    
    def minSpanningTree(self, points):
        source = points[0]
        cost = 0
        
        pq = [(0, points[0])]
        visited = set()
        
        while pq:
            dist, point = heappop(pq)
            
            if tuple(point) in visited:
                continue
            
            # add edge to MST
            cost += dist            
            visited.add(tuple(point))
            
            # loop over neighbours not added to MST
            for next_point in points:
                if tuple(next_point) not in visited:
                    heappush(pq, (self.distance(point, next_point), next_point))
        
        return cost
    
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        return self.minSpanningTree(points)

"""
MST using Prim's algorithm (similar to Dijkstra)

- Consider the points as nodes in a graph.
- Distance between each point is the weight of the edge
  between them.
- We want the minimum spanning tree (MST) of this graph.

number of edges E = n^2
number of vertices V = n
time complexity: ElogV = O(n^2 log(n))
space complexity: O(E) = O(n^2)
"""