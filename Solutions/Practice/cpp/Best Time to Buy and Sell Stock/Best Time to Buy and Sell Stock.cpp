class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];
        
        for (int &price : prices) {
            max_profit = max(max_profit, price - min_price);
            min_price = min(min_price, price);
        }
        
        return max_profit;
    }
};

/*
profit will be maximum if we buy on a day with less price.

- keep track of the minimum price seen so far.
- this will be the buying price at the current index.
- find the maximum of profits obtained by selling at each index.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/