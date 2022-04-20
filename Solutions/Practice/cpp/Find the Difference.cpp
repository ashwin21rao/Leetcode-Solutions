class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        
        for (char &ch : s)
            ans ^= ch;
        for (char ch : t)
            ans ^= ch;
        
        return ans;
    }
};

/*
when we consider the characters of both s and t:
    - every character occurs in a pair (one in s and one in t).
    - only one single character will be unpaired.
    
we need to find this unpaired character.    

hence, we take the xor of all characters in both strings.
    - since a^a = 0, all pairs will cancel out.
    - since o^a = a, only the unpaired character will remain.
    
time complexity: O(m + n)
space complexity: O(1)

https://leetcode.com/problems/find-the-difference/
*/