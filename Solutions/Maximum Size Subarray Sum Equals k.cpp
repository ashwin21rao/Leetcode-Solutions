class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // prefix sum -> smallest index with that prefix sum
        unordered_map<int, int> hash;
        hash[0] = -1;
        
        int sum = 0;
        int max_len = 0;
        int n = nums.size();
        
        for (int i=0; i<n; i++) {
            sum += nums[i];
            
            // subarray with sum k found
            if (hash.find(sum - k) != hash.end())
                max_len = max(max_len, i - hash[sum - k]);
            
            // if current prefix sum does not exist, add it
            if (hash.find(sum) == hash.end())
                hash[sum] = i;
        }
        
        return max_len;
    }
};

/*
- this question is similar to Subarray Sum Equals k.
- here, instead of counting the number of subarrays with sum k,
  we find the longest subarray with size k.

- we calculate the prefix sum of the array.
- we maintain a hashmap which maps the current prefix sum to
  the earliest index at which this prefix sum was found.

- a subarray with sum k ends at index i if we have previously seen 
  a prefix sum of (sum - k).
- the length of this subarray is (i - hash[sum - k]).

time complexity: O(n)
space complexity: O(n)
*/