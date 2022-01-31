class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        for (auto &account : accounts)
            max_wealth = max(max_wealth, accumulate(account.begin(), account.end(), 0));
        
        return max_wealth;
    }
};

/*
find the maximum sum of all rows.

time complexity: O(mn)
space complexity: O(1)

https://leetcode.com/problems/richest-customer-wealth/
*/