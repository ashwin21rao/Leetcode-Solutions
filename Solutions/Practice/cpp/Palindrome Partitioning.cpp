class Solution {
public:
    // returns dp[i][j] = true if str(i, j) is a palindrome
    int findPalindromicSubstrings(int i, int j, string &str, vector<vector<int>> &dp) {
        if (i > j) 
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (str[i] != str[j])
            dp[i][j] = 0;
        else
            dp[i][j] = findPalindromicSubstrings(i+1, j-1, str, dp);
        
        return dp[i][j];
    }
    
    // backtracking to find partitions
    void findPartitions(int i, string &str, vector<vector<int>> is_palindrome,
                        vector<string> partition, vector<vector<string>> &out) {
        
        int n = str.size();
        // partition found
        if (i == n) {
            out.push_back(partition);
            return;
        }
        
        // enumerate all possibilities
        string substr = "";
        for (int j=i; j<n; j++) {
            substr += str[j];
            
            if (is_palindrome[i][j] == 1) {
                // add substring to partition
                partition.push_back(substr);
                // recurse
                findPartitions(j+1, str, is_palindrome, partition, out);
                // remove substring from partition
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string str) {
        int n = str.size();
        
        // find palindromic substrings of str
        vector<vector<int>> is_palindrome(n, vector<int>(n, -1));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                findPalindromicSubstrings(i, j, str, is_palindrome);       
        }
        
        // find all possible partitions
        vector<string> partition;
        vector<vector<string>> out;
        findPartitions(0, str, is_palindrome, partition, out);
        
        return out;
    }
};

/*
we use backtracking to enumerate all possible partitions.

- we construct a dp array to check in constant time whether a substring is a palindrome.
    is_palindrome[i][i] = true if substring from i to j is a palindrome
- this is similar to the longest palindromic substring problem.

Complexity analysis:

- in the worst case, we have a string like "aaaaa" where every substring is a palindrome
- number of partitions = nC0 + nC1 + nC2 + .... + nCn-1 = 2^n where:
    - n = length of string
    - nCk = number of partitions when we make k splits (into k+1 partitions).
- we enumerate all these partitions.

time complexity: O(n * 2^n) since appending the partition takes O(n) time
space complexity: O(n^2) (size of dp array)

without creating the dp array:
    - palindrome checking takes O(n) time.
    - time complexity: O(n * 2^n)
        - this is due to palindrome checking and appending partitions.
        - using dynamic programming eliminates the extra iteration for palindrome checking.
    - space complexity: O(n) (size of the recursion stack).

https://leetcode.com/problems/palindrome-partitioning/
*/