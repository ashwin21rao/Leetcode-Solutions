class Solution {
public:
    // find root of set (with path compression)
    int findRoot(int node, vector<int> &parent) {
        if (node == parent[node])
            return node;
        return parent[node] = findRoot(parent[node], parent);
    }
    
    // find union of 2 disjoint sets
    bool findUnion(int root1, int root2, vector<int> &parent, vector<int> &rank) {        
        // nodes are already part of the same set
        if (root1 == root2)
            return false;
        
        // find union of disjoint sets
        if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
            rank[root2] += rank[root1];
        }
        else {
            parent[root2] = root1;
            rank[root1] += rank[root2];
        }
        
        return true;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // sort by timestamp
        sort(logs.begin(), logs.end());
        
        // DSU for friends graph
        vector<int> parent(n, 0);
        for (int i=0; i<n; i++)
            parent[i] = i;
        
        // rank of node stores number of nodes in subtree
        // rooted at that node
        vector<int> rank(n, 1);
        
        // iterate over all edges
        for (auto &log : logs) {
            int timestamp = log[0];
            int node1 = log[1];
            int node2 = log[2];
            
            // find union of sets of node1 and node2
            int root1 = findRoot(node1, parent);
            int root2 = findRoot(node2, parent);
            findUnion(root1, root2, parent, rank);
            
            // all nodes belong to the same set
            if (rank[root1] == n || rank[root2] == n)
                return timestamp;
        }
        
        // all nodes are never connected
        return -1;
    }
};

/*
sort the logs by timestamp.

we consider the friendship network as a graph:
    - each person a node in the graph.
    - friendship between 2 nodes is an undirected edge between them in the graph.

we keep adding edges to the graph until the entire graph is connected.
when this happens, we return the corresponding timestamp.

we solve this problem using Disjoint Set Union (DSU).
    - initially, each person is a disjoint set.
    - we need to find the earliest timestamp when all nodes become
      part of the same set.
    - hence, we use the size of the graph as the rank of a node.

at each timestamp:
    - find the union of the disjoint sets of the 2 nodes.
    - if after this, the union contains all nodes, we have found the
      required timestamp.
    - since rank is updated only for the roots of the disjoint sets,
      we check if the root of either set equals n after union.

n = number of people
m = number of logs
time complexity: O(mlogm) for sorting + O(n) to create the DSU
space complexity: O(n) to store the DSU

https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
*/