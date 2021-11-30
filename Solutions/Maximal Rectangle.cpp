class Solution {
public:
    // finds next lesser element for each element in heights array
    void findMaxArea(vector<int> &heights, vector<int> &max_rectangles, bool rev) {
        int n = heights.size();
        stack<int> s;
        
        // find next lesser element of each element
        int pos = 0;
        for (int i=0; i<n; i++) {
            // forward or reverse iteration
            pos = rev ? n-1-i : i;
            
            while (!s.empty() && heights[pos] < heights[s.top()]) {
                // area of rectangle between element and its next lesser element
                max_rectangles[s.top()] += abs(pos - s.top()) * heights[s.top()];
                s.pop();
            }
            
            s.push(pos);
        }
        
        // elements which do not have a next lessser element
        pos = rev ? -1 : n;
        while (!s.empty()) {
            max_rectangles[s.top()] += abs(pos - s.top()) * heights[s.top()];
            s.pop();
        }
    }
    
    int findLargestRectangle(vector<int>& heights) {
        int n = heights.size();
        vector<int> max_rectangles(n, 0);
        
        // find max areas starting from the left
        findMaxArea(heights, max_rectangles, false);
        // find max areas starting from the right (in reverse)
        findMaxArea(heights, max_rectangles, true);
        
        int max_area = 0;
        for (int i=0; i<n; i++) {
            // heights[i] counted twice while finding area, so substract it
            max_area = max(max_area, max_rectangles[i] - heights[i]);   
        }
        
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int r = matrix.size(), c = matrix[0].size();
        
        // heights represents the heights of columns of 1s starting at a particular
        // row and going upwards 
        vector<int> heights(c, 0);
        
        int ans = 0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            
            // find maximal rectangle formed by columns ending at row i
            ans = max(ans, findLargestRectangle(heights));
        }
        
        return ans;
    }
};

/*
for each position, we store the max height of a column of 1s starting at that position
and going upwards. we store this in dp[i][j].
dp[i][j] = maximum height of column of 1s starting at (i, j) upwards

the recurrence relation is: dp[i][j] = dp[i-1][j] + 1

now, each row in dp[i][j] represents an array of heights of columns of 1s starting at
that row and going upwards.
we need to find the maximal rectangle which can be created from these heights.
this is the exact question "largest rectangle in histogram".

we find this maximal rectangle for each row in the matrix.
the maximum rectangle from all rows is the answer.

space complexity optimization:
    - since dp[i][j] depends only on the previous row, we only need to store the previous
      row and not the entire dp array.
    - we maintain an array heights which accumulates the heights of columns of 1s.
    - this makes our space complexity O(c) from O(rc).

time complexity: O(rc)
space complexity: O(c)

https://leetcode.com/problems/maximal-rectangle/
*/