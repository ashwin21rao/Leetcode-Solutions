class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int &num : nums)
            ans ^= num;
        
        return ans;
    }
};

/*
- find the xor of all elements of the array.
- duplicate elements will cancel out (a^a = 0)
- the single number remains (since a^0 = a)

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/single-number/
*/