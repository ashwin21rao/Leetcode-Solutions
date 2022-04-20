class Solution:
    def bfs(self, adjList, source, target):
        q = deque([source])
        visited = set([source])
        
        level = 1
        while q:
            size = len(q)
            
            for _ in range(size):
                node = q.popleft()
                
                # target found
                if node == target:
                    return int(level / 2) + 1
                
                for next in adjList[node]:
                    if next not in visited:
                        visited.add(next)
                        q.append(next)
            
            level += 1
        
        # target not found
        return 0
    
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList.append(beginWord)
        
        adjList = defaultdict(list)
        
        # loop over words
        for word in wordList:
            # add edges between word and intermediate words
            for i in range(len(word)):
                intermediate = word[:i] + "*" + word[i+1:]
                adjList[word].append(intermediate)
                adjList[intermediate].append(word)
        
        return self.bfs(adjList, beginWord, endWord)

"""
construct a graph as follows:
    - each word is a node
    - each intermediate word of a given word is a node.
      for example, node: dog, intermediates: *og, d*g, do*
    - undirected edges exist between a node and all its intermediate
      nodes.
    
- we need to find the shortest path between beginWord (source)
  and endWord (target) in this graph.
- this is done using BFS.
- the final answer is the shortest path / 2 
  (since we do not want to count the levels of intermediate nodes)

- each (non-intermediate) node has L edges
- number of edges: nL

time complexity:
    - O(n * L^2) for constructing the graph
    - O(n * L^2) for BFS

space complexity:
    - O(n * L^2) to store the adjacency list

optimization:
    - store nodes as integer values instead of strings.
    - time complexity: O(nL)
    - space complexity: O(nL)
"""