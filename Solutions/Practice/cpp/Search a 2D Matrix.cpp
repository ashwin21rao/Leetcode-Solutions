class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        
        int lb = 0, ub = r * c - 1;
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            int i = mid / c, j = mid % c;
            
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] < target)
                lb = mid + 1;
            else
                ub = mid - 1;
        }
        
        return false;
    }
};

/*
consider the matrix as a 1D array (row major order).
    - this will be sorted in ascending order.
    - we binary search for the target in this array.
    - we can get row and column in the original matrix from 
      mid in binary search.

time complexity: O(log(mn))
space complexity: O(1)

https://leetcode.com/problems/search-a-2d-matrix/
*/