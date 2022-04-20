class Solution:
    def findMinCoins(self, n, coins, dp):
        if dp[n] != -1:
            return dp[n]
        if n == 0:
            return 0
        
        # choose any coin and recurse
        min_coins = math.inf
        for coin in coins:
            if n - coin >= 0:
                min_coins = min(min_coins, self.findMinCoins(n - coin, coins, dp))
        
        dp[n] = 1 + min_coins
        return dp[n]
        
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[n] = minimum coins to make up amount = n
        dp = [-1 for _ in range(amount + 1)]
        
        ans = self.findMinCoins(amount, coins, dp)
        return -1 if ans == math.inf else ans

"""
we have infinite coins.
this is an example of the unbounded knapsack problem.

dp[n] = = minimum coins to make up amount = n
at each stage, we choose any coin and recurse to find dp[n - coin]

c = number of coins
time complexity: O(amount * c)
space complexity: O(amount)
"""