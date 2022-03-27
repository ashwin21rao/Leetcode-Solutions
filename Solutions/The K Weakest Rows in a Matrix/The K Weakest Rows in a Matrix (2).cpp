class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r = mat.size(), c = mat[0].size();
        vector<int> ans;
        
        // handle rows with no 1s
        for (int i=0; i<r; i++) {
            if (mat[i][0] == 0) {
                ans.push_back(i);
            
                // k weakest rows found
                if (ans.size() == k)
                    return ans;   
            }
        }
        
        // vertical iteration of matrix
        for (int j=0; j<c; j++) {
            for (int i=0; i<r; i++) {
                // last 1 in current row
                if (mat[i][j] == 1 && (j == c-1 || mat[i][j+1] == 0)) {
                    ans.push_back(i);
                    
                    // k weakest rows found
                    if (ans.size() == k)
                        return ans;
                }
            }
        }
        
        // should never reach here
        return {};
    }
};

/*
- traverse the matrix vertically (column-wise)

- this ensures that:
    - we reach the rightmost ones of rows with lesser ones first.
    - for 2 rows with same number of ones, we reach the smaller
      row first.
    - hence, this traversal automatically gives us our required 
      sorting order.

- when we are on the rightmost 1 of the current row,
  append that row to the answer.
- continue until we have k rows in the answer.

time complexity: O(rc)
space complexity: O(1)
*/