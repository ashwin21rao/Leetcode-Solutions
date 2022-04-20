class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        
        // dp[i][j] = minimum number of operations to convert
        //            word1(0..i) to word2(0..j)
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        
        // base cases: dp[i][0] and dp[0][j] (handles empty strings)
        dp[0][0] = 0;
        for (int i=1; i<=len1; i++)
            dp[i][0] = i;
        for (int j=1; j<=len2; j++)
            dp[0][j] = j;
        
        // iterative dp
        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
        
        return dp[len1][len2];
    }
};

/*
Iterative implementation.

dp[i][j] = minimum number of operations needed to convert
           word1[0..i] to word2[0..j]
to find: dp[len1-1][len2-1]

we perform operations in word1 to convert it into word2.

- if word1[i] == word2[j], then we do not need any operation
  at the current index i. so, dp[i][j] = dp[i-1][j-1]
  
- else, we can do one of the following operations at the current index i:
    - replace word1[i] with word2[j]: dp[i][j] = 1 + dp[i-1][j-1].
    - delete word1[i]: dp[i][j] = 1 + dp[i-1][j].
    - insert word2[j] into word 1 at index i: dp[i][j] = 1 + dp[i][j-1].
    - we take the minimum of the above 3 operations.

space complexity optimization:
    - dp[i][j] depends only on the current row i and previous row (i-1).
    - so, we only need to store these 2 rows of the dp array.
    - this improves the time complexity to O(min(m, n))
    
time complexity: O(mn)
space complexity: O(mn)

https://leetcode.com/problems/edit-distance/
*/