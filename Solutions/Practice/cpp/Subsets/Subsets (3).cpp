class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subsets;
        
        // loop over all numbers from 0 to 2^n - 1
        int end_i = pow(2, n);
        for (int i=0; i<end_i; i++) {
            vector<int> subset;
            
            // find subset using i as bitmask
            int count = 0;
            int num = i;
            while (num > 0) {
                // bit is set
                if (num & 1)
                    subset.push_back(nums[n-1-count]);
                
                num >>= 1;
                count++;
            }
            
            // add subset to output
            subsets.push_back(subset);
        }
        
        return subsets;
    }
};

/*
- at each index we have 2 options: either include the number or don't.
- we can represent each subset as a bitmask of length n:
    - bitmask[i] = 0 if nums[i] is not included
    - bitmask[i] = 1 if nums[i] is included

- there are 2^n subsets or 2^n bitmasks from 00..00 to 11..11
- these bitmasks correspond to numbers 0 to 2^n - 1 in binary.

the algorithm is as follows:
    - loop over numbers from 0 to 2^n - 1
    - calculate the subset using the current number as bitmask
    
time complexity: O(n * 2^n)
space complexity: O(n) to store the current subset

https://leetcode.com/problems/subsets/
*/