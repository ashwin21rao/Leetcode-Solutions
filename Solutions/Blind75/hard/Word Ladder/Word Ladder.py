class Solution:
    def bfs(self, adjList, source, target):
        q = deque([source])
        visited = set([source])
        
        level = 1
        while q:
            size = len(q)
            
            for _ in range(size):
                node = q.popleft()
                
                # target reached
                if node == target:
                    return level
                
                for next in adjList[node]:
                    if next not in visited:
                        visited.add(next)
                        q.append(next)
                
            level += 1
        
        # target not reached
        return 0
    
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList.append(beginWord)
        wordMap = set(wordList)
        
        # graph
        adjList = defaultdict(list)
        
        # loop over words
        for word in wordList:
            # loop over characters
            for i in range(len(word)):
                # make new word
                for letter in range(ord('a'), ord('z') + 1):
                    new_word = word[:i] + chr(letter) + word[i+1:]
                    
                    # add edge
                    if word != new_word and new_word in wordMap:
                        adjList[word].append(new_word)
        
        # BFS to find shortest path
        return self.bfs(adjList, beginWord, endWord)

"""
construct a graph in which:
    - each word is a node
    - there is an undirected edge bewteen words which differ by a single character
    - the graph is undirected and unweighted.
    
- we need to find the shortest path between beginWord (source)
  and endWord (target) in this graph.
- this is done using BFS.

- each node can have 26 * L edges
- maximum total edges = 26 * n * L

time complexity:
    - O(26 * n * L^2) for constructing the graph
    - O(26 * n * L^2) for BFS

space complexity: 
    - O(26 * n * L^2) to store the adjacency list

optimization:
    - store nodes as integer values instead of strings.
    - time complexity: O(26 * n * L)
    - space complexity: O(26 * n * L)
"""