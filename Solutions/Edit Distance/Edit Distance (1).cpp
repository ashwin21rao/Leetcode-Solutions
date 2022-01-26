class Solution {
public:
    int findMinDistance(int i, int j, string &word1, string &word2, 
                        vector<vector<int>> &dp) {
        
        if (i == -1 || j == -1)
            return i == -1 ? j+1 : i+1;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        // no operation needed at this index
        if (word1[i] == word2[j])
            return dp[i][j] = findMinDistance(i-1, j-1, word1, word2, dp);
        
        // replace insert or delete character at word1[i]
        dp[i][j] = 1 + min({findMinDistance(i-1, j-1, word1, word2, dp),
                            findMinDistance(i,   j-1, word1, word2, dp),
                            findMinDistance(i-1,   j, word1, word2, dp)});
        
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        
        // dp[i][j] = minimum number of operations to convert
        //            word1(0..i) to word2(0..j)
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        
        return findMinDistance(len1-1, len2-1, word1, word2, dp);        
    }
};

/*
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

time complexity: O(mn)
space complexity: O(mn)

https://leetcode.com/problems/edit-distance/
*/