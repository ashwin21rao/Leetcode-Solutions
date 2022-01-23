class Solution {
public:
    bool findWinner(int n, int player, vector<vector<int>> &dp) {
        if (dp[n][player] != -1)
            return dp[n][player];
        
        // alice wins
        if (n == 0)
            return dp[n][player] = (player == 1);
        
        // check all possible moves
        for (int i=1; i<=sqrt(n); i++) {
            bool winner = findWinner(n - pow(i, 2), 1 - player, dp);
            
            // Alice wins
            if (player == 0 && winner)
                return dp[n][player] = true;
            // Bob wins
            if (player == 1 && !winner)
                return dp[n][player] = false;
        }
        
        return dp[n][player] = (player == 1);
    }
    
    bool winnerSquareGame(int n) {
        // dp[n][player] = true if alice wins when there are n stones 
        // and it is player's turn
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        return findWinner(n, 0, dp);
    }
};

/*
dp[n][player] = true if alice wins when there are n stones 
                and it is player's turn
                
to find: dp[n][0] (0 -> alice, 1 -> bob)

when we have n stones, we can remove any perfect square
number of stones <= n.

- if it is Alice's turn, she wins if for any possible move,
  she wins (Bob loses), since she will pick this move optimally.
- if it is Bob's turn, he wins if for any possible move,
  he wins (Alice loses), since he will pick this move optimally.

time comlpexity: O(n sqrt(n))
space complexity: O(n)

https://leetcode.com/problems/stone-game-iv/solution/
*/