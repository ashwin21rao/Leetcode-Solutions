# Graph algorithms

## Cycle Detection

### Detect cycles in an undirected graph

- DFS.
- If we reach a visited node that is not the parent of the current node, then there is a cycle.

### Detect cycles in a directed graph

- DFS.
- We keep track of the chain of nodes in the current DFS path. If we reach a node in the chain, then there is a cycle.

## Shortest path algorithms

### Shortest path between 2 nodes in an unweighted graph

- BFS.

### Single source shortest path

- Dijkstra (weighted graph)
- BFS (unweighted graph)

### Minimum Spanning Tree

- Prim


# Tree algorithms

### Traversals

- Inorder: Left, node, right (node second)
- Preorder: Node, left, right (node first)
- Postorder: Left, right, node (node last)

# Data Structures

### Segment Tree

- Useful for performing range queries on an array in O(log n) time. For example:
	- Finding the sum of all elements in the range [l, r]
	- Finding the minimum/maximum value in the range [l, r]

- Time complexity of range queries: O(log n)
- Space needed to store the segment tree: O(n)

