class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);
        
        // construct adjacency list
        for (auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        // node, level
        queue<pair<int, int>> q;
        
        // fill queue with leaf nodes (nodes with degree 1)
        for (int i=0; i<n; i++) {
            if (degree[i] == 1)
                q.push({i, 0});
        }
        
        // peeling onion
        int prev_level = -1;
        vector<int> nodes;
        
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            
            if (level != prev_level) {
                nodes.clear();
                prev_level = level;
            }
            nodes.push_back(node);
            
            for (int &next : adjList[node]) {
                degree[next]--;
                
                // if next node is a leaf node after removing current node
                if (degree[next] == 1)
                    q.push({next, level + 1});
            }
        }
        
        return nodes;
    }
};

/*
we solve this problem using the peeling onion technique.
this is similar to kahn's algorithm for topological sorting.

for the height of the tree to be minimum, the root needs to be at the "center" of the tree.
- these "central" nodes are called the centroid of the tree.
- there are either 1 or 2 centroids in a tree.
- we need to find these centroids.

the idea is as follows:
    - in each iteration, we "peel" off the outermost layer of the tree (consisting of leaf nodes).
    - after removing this layer, new leaf nodes will be formed, which we peel off next.
    - we continue this process till we are at the innermost (center) layer of nodes.
    - these nodes are the required roots for minimum height trees.

- the degree of a node is the number of edges connected to it.
- a leaf node has degree 1.
- when we remove a node, we simply decrease the degree of its neighbouring nodes by 1.

we perform multi-source BFS (similar to Kahn's algorithm) as follows:
    - start with all leaf nodes (degree = 1) as sources.
    - remove all leaf nodes. if new leaf nodes are formed in the process, add them to the queue.
    - continue till there are no nodes left.
    
V = n
E = n-1
time complexity: O(V + E) = O(n)
space complexity: O(V + E) = O(n)

https://leetcode.com/problems/minimum-height-trees/
*/