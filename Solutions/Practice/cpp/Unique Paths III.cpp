class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, unordered_set<int> &visited,
             int num_empty, int &ans) {
        
        int r = grid.size(), c = grid[0].size();
        visited.insert(c * i + j);
        
        // goal reached
        if (grid[i][j] == 2) {
            // all empty cells visited
            if (visited.size() == num_empty + 2)
                ans++;
            
            visited.erase(c * i + j);
            return;
        }
        
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto &dir : dirs) {
            int next_i = i + dir[0], next_j = j + dir[1];
            
            if (next_i < 0 || next_i == r || next_j < 0 || next_j == c)
                continue;
            
            // go to next cell
            if (visited.find(c * next_i + next_j) == visited.end() && 
                grid[next_i][next_j] != -1) {
                dfs(next_i, next_j, grid, visited, num_empty, ans);
            }
        }
        
        // leave cell
        visited.erase(c * i + j);
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        // find position of starting square and number of empty cells
        int start_i, start_j, num_empty = 0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j] == 0)
                    num_empty++;
                else if (grid[i][j] == 1)
                    start_i = i, start_j = j;
            }
        }
        
        // keeps track of visited cells
        unordered_set<int> visited;
        
        int ans = 0;
        dfs(start_i, start_j, grid, visited, num_empty, ans);
        return ans;
    }
};

/*
we use dfs/backtracking to enumerate all possible paths from source to destination.

we maintain a visited array to keep track of all visited cells.
when we reach the end node, we increment the answer only if all empty cells have been
visited by checking the size of the visited array.

each call to the recursive function can make upto 3 recursive calls.
the maximum recursion depth is the number of cells = mn

time complexity: O(3^mn)
space complexity: O(mn)

https://leetcode.com/problems/unique-paths-iii/
*/