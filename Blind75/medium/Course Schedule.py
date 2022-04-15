class Solution:
    def findTopologicalOrdering(self, adjList):
        n = len(adjList)
        in_degree = [0 for _ in range(n)]
        
        # find in degrees of all nodes
        for i in range(n):
            for node in adjList[i]:
                in_degree[node] += 1
        
        # all nodes with in degree 0 are sources of BFS
        q = deque([])
        for i in range(n):
            if in_degree[i] == 0:
                q.append(i)
        
        ordering = []
        
        # multi source BFS
        while q:
            node = q.popleft()
            ordering.append(node)
            
            for next in adjList[node]:
                in_degree[next] -= 1
                if in_degree[next] == 0:
                    q.append(next)
        
        return len(ordering) == n
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = [[] for _ in range(numCourses)]
        
        for course1, course2 in prerequisites:
            adjList[course2].append(course1)
        
        return self.findTopologicalOrdering(adjList)

"""
consider a directed graph in which:
    - each node is a course
    - a directed edge is present from a to b if a is a
      prerequisite of b.

we need to find a valid topological ordering of this graph.
this means that we found an order to complete all courses.

n = number of courses
e = size of prerequisites array
time complexity: O(n + e)
space complexity: O(n + e)
"""