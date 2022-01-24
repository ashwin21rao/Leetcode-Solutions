class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1)
            return true;
        
        // whether all letters should be uppercase or lowercase
        bool capital = isupper(word[0]) && isupper(word[1]);
        
        for (int i=1; i<n; i++) {
            if ((capital && islower(word[i])) || (!capital && isupper(word[i])))
                return false;
        }
        
        return true;
    }
};

/*
- if the first and second letter of the word are both capital,
  then all letters must be capital.
- else, all letters after the first letter must be lowercase.

time complexity: O(n) (early breaking improves complexity)
space complexity: O(1)

https://leetcode.com/problems/detect-capital/
*/