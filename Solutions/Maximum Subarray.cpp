class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = -1e9;
        
        for (int &num : nums) {
            sum += num;
            max_sum = max(max_sum, sum);
            sum = max(sum, 0);
        }
        
        return max_sum;
    }
};

/*
Kadane's algorithm for maximum subarray sum.

When we encounter a negative cumulative sum:
    - we ignore the previous subarray
    - we reset cumulative sum = 0 and find sum starting from the current position
    
time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/maximum-subarray/submissions/
*/