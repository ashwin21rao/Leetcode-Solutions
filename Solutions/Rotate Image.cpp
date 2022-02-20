class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // find transpose of matrix
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        
        // reverse each row of matrix
        for (auto &row : matrix)
            reverse(row.begin(), row.end());        
    }
};

/*
we rotate the matrix by 90 degrees in 2 steps:
    - transpose the matrix
    - reverse each row of the matrix

time complexity: O(n^2)
space complexity: O(1)

https://leetcode.com/problems/rotate-image/
*/