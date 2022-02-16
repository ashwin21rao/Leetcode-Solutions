class Solution {
public:
    // returns number of levels of BFS traversal
    int bfs(queue<pair<int, int>> &q, vector<vector<int>> &grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // multi-source BFS
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            
            for (int k=0; k<size; k++) {
                auto [i, j] = q.front();
                q.pop();
                
                // loop over all neighbours
                for (auto &dir : dirs) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    
                    if (new_i < 0 || new_i == r || new_j < 0 || new_j == c)
                        continue;
                                        
                    // non-rotten orange neighbour
                    if (grid[new_i][new_j] == 1) {
                        grid[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                    }
                }
            }
            level++;
        }
        
        return level;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;
        
        // all rotten oranges are sources of BFS
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        // BFS to make adjacent oranges rotten
        int minutes = bfs(q, grid) - 1;
        
        // some oranges are still fresh
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        
        // handle case when there are no oranges
        return max(minutes, 0);
    }
};

/*
- we perform multi-source BFS from all rotten oranges as sources.
- let d be the maximum level of the BFS traversal
    - if there are fresh oranges left after BFS, return -1.
    - if there are no oranges in the grid, return 0.
    - else, the required number of minutes is d.

time complexity: O(rc)
space complexity: O(rc) to store the queue

https://leetcode.com/problems/rotting-oranges/
*/