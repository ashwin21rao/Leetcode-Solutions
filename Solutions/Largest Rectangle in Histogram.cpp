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
    
    int largestRectangleArea(vector<int>& heights) {
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
};

/*
- for each height, we find the area of the rectangle formed between each element 
  and its next lesser element in the heights array.
- when doing this in the forward direction, we get the area of the maximum rectangle
  starting at each element and going to the right.
- when doing this in the reverse direction, we get the area of the maximum rectangle
  starting at each element and going to the left.
- the area of the maximum rectangle formed from each height will be the sum of these 
  2 values. since we count the element twice (forward and reverse), we subtract it once.
- the maximum of all these rectangle areas found for each height is our answer.

time complexity: O(n)
space complexity: O(n)

https://leetcode.com/problems/largest-rectangle-in-histogram/
*/