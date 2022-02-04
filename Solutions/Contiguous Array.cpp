class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // prefix sum -> smallest index with that prefix sum
        unordered_map<int, int> hash;
        hash[0] = -1;
        
        int sum = 0;
        int max_len = 0;
        int n = nums.size();
        
        for (int i=0; i<n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            
            // subarray with sum 0 found
            if (hash.find(sum) != hash.end())
                max_len = max(max_len, i - hash[sum]);
            // if current prefix sum does not exist, add it
            else
                hash[sum] = i;
        }
        
        return max_len;
    }
};

/*
this question is similar to Maximum Size Subarray Sum Equals k.

- we need to find the longest subarray with equal number of 0s and 1s.
- replace every 0 with -1.
- subarrays with equal number of 0s and 1s have sum equal to 0.
- hence, we find the longest subarray with sum 0.

time complexity: O(n)
space complexity: O(n)
*/