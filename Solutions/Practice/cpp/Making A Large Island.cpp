class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // returns size of island rooted at (i, j)
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &island_nums,
            int island_num) {
        
        int n = grid.size();
        island_nums[i][j] = island_num;
        
        int size = 1;
        for (auto &dir : dirs) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if (new_i < 0 || new_i == n || new_j < 0 || new_j == n)
                continue;
            
            // cell not visited
            if (grid[new_i][new_j] == 1 && island_nums[new_i][new_j] == -1)
                size += dfs(new_i, new_j, grid, island_nums, island_num);
        }
        
        return size;
    }
    
    // returns size of largest island after changing a 0 to 1
    int findLargestIsland(vector<vector<int>> &grid, vector<vector<int>> &island_nums,
                          unordered_map<int, int> &island_sizes) {
        
        int n = grid.size();
        
        // initialize max size to maximum island size
        int max_size = 0;
        for (auto &[num, size] : island_sizes)
            max_size = max(max_size, size);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1)
                    continue;
                
                // islands surrounding current 0
                unordered_set<int> islands;
                
                // check all directions
                int size = 1;
                
                for (auto &dir : dirs) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i < 0 || new_i == n || new_j < 0 || new_j == n)
                        continue;
                    if (grid[new_i][new_j] == 0)
                        continue;
                    
                    int island = island_nums[new_i][new_j];
                    
                    // new neightbouring island
                    if (islands.find(island) == islands.end()) {
                        size += island_sizes[island];
                        islands.insert(island);
                    }
                }
                
                max_size = max(max_size, size);
            }
        }
        
        return max_size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // island number of each cell
        vector<vector<int>> island_nums(n, vector<int>(n, -1));
        // island number -> size
        unordered_map<int, int> island_sizes;
        
        // assign island numbers
        int island_num = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                // cell not visited
                if (grid[i][j] == 1 && island_nums[i][j] == -1) {
                    island_sizes[island_num] = dfs(i, j, grid, island_nums, island_num);
                    island_num++;
                }
            }
        }
        
        // find max island size
        return findLargestIsland(grid, island_nums, island_sizes);
    }
};

/*
- we assign each island a unique number. 
  for each node, we store the island number it belongs to.
- for each island, we store its size.
  we use an hashmap to store the size of each island number.

1) calculate the size of each island and assign island numbers
   to each cell. 

2) loop over all 0's and calculate the size of the island formed
   by converting it to a 1. when converting a 0 to 1:
     - check all neighbouring 1's (4 directions)
     - if the neighbouring island number has not been seen already,
       add its size to the current size.

time complexity: O(n^2): we make 2 passes over the grid
space complexity: O(n^2) to store island numbers of cells

https://leetcode.com/problems/making-a-large-island/
*/