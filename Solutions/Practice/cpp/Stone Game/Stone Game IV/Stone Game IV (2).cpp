class Solution {
public:
    bool findWinner(int n, vector<int> &dp) {
        if (dp[n] != -1)
            return dp[n];
        
        for (int i=1; i<=sqrt(n); i++) {
            // if next player loses, current player wins
            if (!findWinner(n - pow(i, 2), dp))
                return dp[n] = true;
        }
        
        // next player won for all moves of current player
        return dp[n] = false;
    }
    
    bool winnerSquareGame(int n) {
        // dp[n] = true if the current player wins
        vector<int> dp(n+1, -1);
        
        return findWinner(n, dp);
    }
};

/*
dp[n] = true if the current player wins
to find: dp[0]

- The current player wins if for any move, the next player loses.
    - Alice wins if for any move, Bob loses.
    - Bob wins if for any move, Alice loses.
- The current player loses if for all moves, the next player wins.

time complexity: O(n sqrt(n))
space complexity: O(n)

https://leetcode.com/problems/stone-game-iv/solution/
*/