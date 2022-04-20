class Solution {
public:
    // dfs traversal over all connected 'O's
    void dfs(int i, int j, vector<vector<char>> &board) {
        board[i][j] = '.';
        
        int r = board.size(), c = board[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (auto &dir : dirs) {
            int new_i = i + dir[0], new_j = j + dir[1];
            
            if (new_i < 0 || new_i == r || new_j < 0 || new_j == c)
                continue;
            if (board[new_i][new_j] == 'O')
                dfs(new_i, new_j, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();
        
        // perform dfs for all 'O's at the edges of the board
        for (int i=0; i<r; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][c-1] == 'O') dfs(i, c-1, board);
        }
        for (int j=0; j<c; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[r-1][j] == 'O') dfs(r-1, j, board);
        }
        
        // flip visited 'O's back to 'O' and unvisited 'O's to 'X'
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (board[i][j] == '.')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

/*
using dfs, we visit all 'O's connected to the edge of the board.
we convert the remaining unvisited 'O's to 'X's.

time complexity: O(mn)
space complexity: O(1

https://leetcode.com/problems/surrounded-regions/
*/