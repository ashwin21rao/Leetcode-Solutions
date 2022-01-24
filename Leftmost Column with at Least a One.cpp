/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int search(int i, int c, BinaryMatrix &binaryMatrix) {
        int lb = 0, ub = c-1;
        
        int ans = c;
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            
            if (binaryMatrix.get(i, mid) == 1) {
                ans = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
        
        return ans;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int r = dim[0], c = dim[1];
        
        // loop over each row in the matrix
        int ans = c;
        for (int i=0; i<r; i++) {
            // binary search for leftmost 1 in each row
            ans = min(ans, search(i, c, binaryMatrix));
            
            if (ans == 0)
                break;
        }
        
        return ans == c ? -1 : ans;
    }
};

/*
each row is sorted in non-decreasing order.
for each row, we binary search for the leftmost 1.
the minimum of all these positions is the required answer.

time complexity: O(nlogn)
space complexity: O(1)

https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
*/