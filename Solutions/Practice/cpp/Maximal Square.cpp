class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        
        // dp[i][j] = side of maximal square with bottom right corner (i, j)
        vector<vector<int>> dp(r, vector<int>(c, 0));
        int max_side = 0;
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (matrix[i][j] == '0')
                    continue;
                
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});

                max_side = max(max_side, dp[i][j]);
            }
        }
        
        return pow(max_side, 2);
    }
};

/*
dp[i][j] = side of maximal square with bottom right corner (i, j)
to find: maximum value in the dp array
recurrence relation: dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

space optimization:
    - to find dp[i][j], we use only the previous row and column.
    - hence, we do not need to store the entire dp array.
    - this reduces space complexity to O(min(r, c))

time complexity: O(rc)
space complexity: O(rc)

https://leetcode.com/problems/maximal-square/
*/