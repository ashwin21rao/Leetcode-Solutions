class Solution {
public:
    // returns true if a node with value 0 was visited during dfs
    bool dfs(int i, vector<int> &arr, vector<bool> &visited) {
        int n = arr.size();

        if (i >= n || i < 0 || visited[i]) 
            return false;
        
        visited[i] = true;
        
        // if node has value zero, return immediately
        if (arr[i] == 0)
            return true;
        
        // dfs on children: i + arr[i] and i - arr[i]
        return dfs(i + arr[i], arr, visited) || dfs(i - arr[i], arr, visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        
        return dfs(start, arr, visited);
    }
};

/*
we construct a directed graph using the given array:
    - each index in the array is a node.
    - there is a directed edge from i to i + arr[i].
    - there is a directed edge from i to i - arr[i].
    
now, we need to check if we can visit any node with value 0 starting at the start node.
this is done using dfs from the start node.
as soon as we find a node with value 0, we no longer need to traverse the 
rest of the graph.

space optimization:
    - the adjacency list does not need to be created.
    - since we know the edges connecting nodes in the graph, we can directly call dfs
      on i + arr[i] and i - arr[i] from node i.

V = n, E = 2n
time complexity: O(V + E) = O(n)
space complexity: O(n) for visited array

https://leetcode.com/problems/jump-game-iii/
*/