class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        long height_sum = 0;
        long ladder_sum = 0;
        
        // stores the k largest height differences (for which ladders will be used)
        priority_queue<int, vector<int>, greater<>> largest_heights;
        
        int n = heights.size();
        for (int i=0; i<n-1; i++) {
            // we need to use bricks or a ladder
            if (heights[i] < heights[i+1]) {
                int height_diff = heights[i+1] - heights[i];
                height_sum += height_diff;
                
                largest_heights.push(height_diff);
                ladder_sum += height_diff;
                
                if (largest_heights.size() > ladders) {
                    ladder_sum -= largest_heights.top();
                    largest_heights.pop();
                }
                
                // cannot go from building i to i+1
                if (height_sum - ladder_sum > bricks)
                    return i;
            }
        }
        
        // can reach the end
        return n-1;
    }
};

/*
we greedily use bricks and ladders as follows:
    - ladders are used for the maximum heights to be climbed.
    - bricks are used for the remaining heights.
    - this minimizes the number of bricks used.

- we keep track of the sum of all height differences seen till the 
  current position (= height_sum).

- the largest k (= number of ladders) of these height differences will
  be climbed using ladders. the remaining heighs will be climbed using bricks.
    - we maintain a min-heap (priority queue) to keep track of the
      k largest height differences seen till the current position.
    - this helps us keep track of the running sum of the top k
      largest height differences (= ladder_sum)

- the number of bricks needed to cross the current position is hence
  equal to (height_sum - ladder_sum). if this is less than the number of
  available bricks, we cannot go beyond the current building.
  
time complexity: O(nlogn)
space complexity: O(n)

https://leetcode.com/problems/furthest-building-you-can-reach/
*/