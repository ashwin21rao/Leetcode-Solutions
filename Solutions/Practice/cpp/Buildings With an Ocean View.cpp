class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int max_height = 0;
        vector<int> ans;
        
        for (int i=n-1; i>=0; i--) {
            if (max_height < heights[i])
                ans.push_back(i);
            
            max_height = max(max_height, heights[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
we need to find all elements such that there is no element greater
than it to its right.

- we find the cumulative maximum from the end of the array in reverse order.
- for each index i, if the maximum height in (i+1, n) < heights[i]:
    - all elements to the right of index i are shorter than heights[i].
    - so, the building at i has an ocean view.

since we add indices in reversr order, we reverse the ans at the end.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/buildings-with-an-ocean-view/
*/