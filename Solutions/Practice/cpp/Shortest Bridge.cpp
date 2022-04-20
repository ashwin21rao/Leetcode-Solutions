class Solution {
public:
    // dfs to find all 1's of the first island
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited,
         queue<pair<pair<int, int>, int>> &q) {
    
        int r = grid.size(), c = grid[0].size();
        
        // add cell as source of BFS
        q.push({{i, j}, 0});
        visited[i][j] = true;

        // loop over neighbours
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto &dir : dirs) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i < 0 || new_i == r || new_j < 0 || new_j == c)
                continue;
            if (grid[new_i][new_j] == 1 && !visited[new_i][new_j])
                dfs(new_i, new_j, grid, visited, q);
        }
    }
    
    // multi-source bfs to find shortest distance between islands
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited,
            queue<pair<pair<int, int>, int>> &q) {

        int r = grid.size(), c = grid[0].size();

        while (!q.empty()) {
            auto [node, level] = q.front();
            auto [i, j] = node;
            q.pop();

            // loop over neighbours
            vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto &dir : dirs) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if (new_i < 0 || new_i == r || new_j < 0 || new_j == c)
                    continue;
                
                if (!visited[new_i][new_j]) {
                    // new island reached (unvisited cell containing 1)
                    if (grid[new_i][new_j] == 1)
                        return level;
                    
                    // add to queue
                    q.push({{new_i, new_j}, level + 1});
                    visited[new_i][new_j] = true;
                }
            }
        }

        // should not reach here
        return -1;
    }

    int shortestBridge(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c, 0));
        
        // {i, j} -> level
        queue<pair<pair<int, int>, int>> q;

        // sources of BFS are all 1's of first island
        for (int i=0; i<r; i++) {
            bool found = false;
            for (int j=0; j<c; j++) {
                if (matrix[i][j] == 1) {
                    dfs(i, j, matrix, visited, q);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        // find shortest distance between islands
        return bfs(matrix, visited, q);
    }
};

/*
- we need to find the shortest distance between 2 islands.
- we use multi-source BFS with all 1's of the first island
  as source. these are found using DFS.
- when we reach an unvisited 1, this means we have reached the 
  second island. the current level is the required distance.

time complexity: O(rc) for both DFS and BFS.
space complexity: O(rc) to store the visited array and queue.

https://leetcode.com/problems/shortest-bridge/
*/