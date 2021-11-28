class Solution {
public:
    void findPaths(int node, int dest, vector<vector<int>> &adjList,
                   vector<int> &path, vector<vector<int>> &out) {
        
        // include current node in path
        path.push_back(node);
        
        // destination reached
        if (node == dest) {
            out.push_back(path);
            path.pop_back();
            return;
        }
        
        // go to all children nodes
        for (int &next : adjList[node])
            findPaths(next, dest, adjList, path, out);
        
        // remove current node from path
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> out;
        vector<int> path;
        
        findPaths(0, n-1, graph, path, out);
        return out;
    }
};

/*
we use backtracking to enumerate all paths in the graph.
there can be a maximum of 2^n paths, of maximum length n.

time complexity: O(2^n * n)
space complexity: O(2^n * n)

https://leetcode.com/problems/all-paths-from-source-to-target/
*/