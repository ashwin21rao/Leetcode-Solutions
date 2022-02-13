class Solution {
public:
    // enumerates all subsets using backtracking
    void findAllSubsets(int i, vector<int> &nums, vector<int> &subset, vector<vector<int>> &subsets) {
        // subset generated
        if (i == nums.size()) {
            subsets.push_back(subset);
            return;
        }
        
        // do not include nums[i] in subset
        findAllSubsets(i+1, nums, subset, subsets);
        
        // include nums[i] in subset
        subset.push_back(nums[i]);
        findAllSubsets(i+1, nums, subset, subsets);
        subset.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        
        findAllSubsets(0, nums, subset, subsets);
        return subsets;
    }
};

/*
- we use backtracking to enumerate all possible subsets 
  of the given set.
- for each number in the set, we have 2 options: 
  either include it in the current subset or dont.

time complexity: O(n * 2^n)
space complexity: O(n) to store the current subset

https://leetcode.com/problems/subsets/
*/