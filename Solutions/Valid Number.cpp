class Solution {
public:
    // returns true if at least 1 digit was consumed
    bool consumeDigits(string &str, int &i) {
        int start_i = i;
        while (i < str.size() && isdigit(str[i]))
            i++;
        
        return start_i != i;
    }
    
    bool isNumber(string str) {
        int n = str.size();
        int i = 0;
        
        // consume integer or part of decimal before '.'
        // consume sign if any
        if (str[i] == '+' || str[i] == '-')
            i++;
        
        // consume digits before '.'
        bool exists1 =  consumeDigits(str, i);
        bool exists2 = false;
        
        // consume '.' and following digits
        if (i < n && str[i] == '.')
            exists2 = consumeDigits(str, ++i);
        
        // decimal or integer without 'e'
        if (!exists1 && !exists2)
            return false;
        else if (i == n)
            return true;
        
        // consume 'e'
        if (str[i] != 'e' && str[i] != 'E')
            return false;
        i++;
        
        // consume integer after 'e'
        // consume sign if any
        if (i < n && (str[i] == '+' || str[i] == '-'))
            i++;
        
        // consume digits
        if (!consumeDigits(str, i))
            return false;
        
        return i == n;
    }
};

/*
follow the rules directly.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/valid-number/
*/