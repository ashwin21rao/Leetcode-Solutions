class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        // reverse entire array
        reverse(nums.begin(), nums.end());
        
        // reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // reverse remaining array
        reverse(nums.begin() + k, nums.end());
    }
};

/*
CONSTANT SPACE SOLUTION:
    - reverse the entire array.
    - reverse the first k elements of the array.
    - reverse the last k elements of the array.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/rotate-array/
*/