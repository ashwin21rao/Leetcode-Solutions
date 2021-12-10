class Solution {
public:
    int findTilings(int i, int n, vector<int> &dp) {
        if (i == n) return 1;
        if (dp[i] != 0) return dp[i];
        
        // recursion base cases
        if (i == n-1) return dp[i] = 1;
        if (i == n-2) return dp[i] = 2;
        
        // dp[i] = 2dp[i+1] + dp[i+3]
        int M = 1e9 + 7;
        return dp[i] = ((2 * findTilings(i+1, n, dp)) % M + findTilings(i+3, n, dp)) % M;
    }
    
    int numTilings(int n) {
        vector<int> dp(n, 0);
        return findTilings(0, n, dp);
    }
};

/*
this question is similar to the finding the number of ways to reach the top
of a staircase from the bottom.

dp[i] = number of ways to tile from position i to n
to find: dp[0]

at each index i, we have the following atomic options:
    - add a single vertical domino and go to position i+1
    - add two vertical dominos stacked horzontally and go to position i+2
    - to take a step greater than 2 indices, we can do it using 2 trominos and
      a certain number of dominos in between them. This can be done in 2 ways 
      (flip along horizontal axis). this is true for all steps of size > 2.
    
so, the recurrence relation becomes:
dp[i] = dp[i+1] + dp[i+2] + 2 * (dp[i+3] + dp[i+4] + ... + dp[n-1])

this can be simplified:
    - dp[i] = dp[i+1] + dp[i+2] + 2 * (dp[i+3] + dp[i+4] + ... + dp[n-1])
    - dp[i+1] = dp[i+2] + dp[i+3] + 2 * (dp[i+4] + ... + dp[n-1])
so, dp[i] = 2 * dp[i+1] + dp[i+3]

base cases:
    - dp[n-1] = 1
    - dp[n-2] = 2

space complexity optimization:
    - since dp[i] depends only on dp[i+1] and dp[i+3], we need to store only these values.
    - this makes the space complexity O(1)

time complexity: O(n)
space complexity: O(n), can be optimized to O(1)

https://leetcode.com/problems/domino-and-tromino-tiling/
*/