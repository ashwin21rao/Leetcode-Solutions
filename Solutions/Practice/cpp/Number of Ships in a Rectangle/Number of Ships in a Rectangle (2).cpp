/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:    
    // divide and conquer along x and y direction simultaneously
    int countInGrid(int x1, int x2, int y1, int y2, Sea &sea) {
        // invalid rectangle
        if (x1 > x2 || y1 > y2)
            return 0;
        
        // discard entire grid
        if (!sea.hasShips(vector<int>({x2, y2}), vector<int>({x1, y1})))
            return 0;
        
        // base case of recursion (rectangle is a point)
        if (x1 == x2 && y1 == y2)
            return 1;
        
        // split grid into 4 parts (split in half along x-axis and y-axis)
        int x_mid = x1 + (x2 - x1) / 2;
        int y_mid = y1 + (y2 - y1) / 2;
        
        return countInGrid(x1, x_mid, y1, y_mid, sea) + 
               countInGrid(x1, x_mid, y_mid + 1, y2, sea) + 
               countInGrid(x_mid + 1, x2, y1, y_mid, sea) + 
               countInGrid(x_mid + 1, x2, y_mid + 1, y2, sea); 
    }
    
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x1 = bottomLeft[0], x2 = topRight[0];
        int y1 = bottomLeft[1], y2 = topRight[1];
        
        return countInGrid(x1, x2, y1, y2, sea);
    }
};

/*
this is the 2D divide and conquer approach.

NAIVE APPROACH:
- we linearly query all points and count the number of ships.
DIVIDE AND CONQUER (OPTIMIZED):
- we divide the grid in half along a direction.
- if any half does not contain any ships, we discard it immediately and 
  do not need to explore that half.
- this reduces the number of API calls.

1D divide and conquer:
    - we apply divide and conquer in both directions, one after the other.
    - we first split the grid into halves along the y-axis.
    - when we are left with a single line (y1 == y2), we
      divide and conquer along the x-axis for that row.
    
2D divide and conquer:
    - we apply divide and conquer in both directions simultaneously.
    - we split the grid into halves both in the x and y direction.
      this gives us 4 smaller subgrids to search for ships in.

2D divide and conquer complexity analysis:
    S = number of ships
    M, N = dimensions of grid
    time complexity: O(S * log(max(M, N))) 
        since we divide and conquer along both directions simultaneously
    space complexity: O(log(max(M, N))): height of the recursion stack

1D divide and conquer complexity analysis:
    S = number of ships
    M, N = dimensions of grid
    time complexity: O(S * log(MN)))
        since we divide and conquer along both directions one after the other
    space complexity: O(log(MN)): height of the recursion stack
*/