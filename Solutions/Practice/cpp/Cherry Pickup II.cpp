class Solution {
public:    
    // returns dp[i][j1][j2]
    int findMaxCherries(int i, int j1, int j2, vector<vector<vector<int>>> &dp, 
                        vector<vector<int>> &grid) {
        
        int r = grid.size(), c = grid[0].size();
        
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        // robots reached last row
        if (i == r-1) {
            if (j1 != j2)
                return grid[i][j1] + grid[i][j2];
            return grid[i][j1];
        }
        
        // accumulate answer
        int max_cherries = 0;
        
        // all possible directions a robot can move
        int next_i = i + 1;
        vector<int> j_dirs = {-1, 0, 1};
        
        // possible moves of robot1
        for (auto &dir1 : j_dirs) {
            int next_j1 = j1 + dir1;
            
            // robot1 leaves grid (unoptimal)
            if (next_j1 < 0 || next_j1 == c)
                continue;
            
            // possible moves of robot2
            for (auto &dir2 : j_dirs) {
                int next_j2 = j2 + dir2;
                
                // robot2 leaves grid (unoptimal)
                if (next_j2 < 0 || next_j2 == c)
                    continue;
                
                int cherries = findMaxCherries(next_i, next_j1, next_j2, dp, grid);
                max_cherries = max(max_cherries, cherries);
            }
        }
        
        // robots are not on the same cell
        if (j1 != j2)
            dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + max_cherries;
        else
            dp[i][j1][j2] = grid[i][j1] + max_cherries;
        
        return dp[i][j1][j2];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        // dp[i][j1][j2] = max cherries robots can pick starting at (i, j1) and (i, j2)
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        
        return findMaxCherries(0, 0, c-1, dp, grid);
    }
};

/*
we need to find the maximum amount of cherries collected when:
    - robot1 starts from (0, 0)
    - robot2 starts from (0, c-1)

Consider the case where we only have a single robot starting at (0, 0):

- dp[i][j] = maximum number of cherries collected by the robot starting at (i, j)
- recurrence relation:
    dp[i][j] = grid[i][j] + max(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1])
- to find: dp[0][0]

We now extend this to 2 robots:

- dp[i1][j1][i2][j2] = max cherries robots can pick starting at (i1, j1) and (i2, j2)
- here, each robot moves down one row in each step. hence, it is guaranteed that 
  at any time, both robots will have the same value of i (i1 = i2).
- hence, we can write the dp as: dp[i][j1][j2] = max cherries robots can pick starting at (i, j1) and (i, j2)

at each stage, robot1 can move to 3 cells and robot2 can move to 3 cells.
    - this gives us 9 possible combinations of moves of both robots.
    - we choose the combination which results in the highest number of picked cherries.
    - let this combination be robot1: j1 -> new_j1 and robot2: j2 -> new_j2.
    - if robots are not on the same cell:
        dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + dp[i+1][new_j1][new_j2] 
    - else:
        dp[i][j1][j2] = grid[i][j1] + dp[i+1][new_j1][new_j2]
    - if any robot leaves the extent of the grid, this is an unoptimal case (since grid[i][j] >= 0).
      we can reject this case directly.
    
space complexity optimization (iterative dp + state compression):
    - one row in the dp array (dp[i][][]) depends only on the next row (dp[i+1][][]).
    - hence, we do not need to store all rows, and instead can store only the previous row.
    - hence, we only need to store dp[j1][j2] at any given time.
    - optimized space complexity: O(c^2)

time complexity: O(r * c^2)
space complexity: O(r * c^2)

https://leetcode.com/problems/cherry-pickup-ii/
*/