class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int i = 0;
        int ans = 0;
        
        // remove spaces
        while (i < n && str[i] == ' ')
            i++;
        if (i == n)
            return ans;
        
        // remove operator
        int sign = 1;        
        if (str[i] == '+') 
            i++;
        else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        
        // read digits
        while (i < n && isdigit(str[i])) {
            int d = str[i] - '0';
            
            // check for overflow
            if (ans > (INT_MAX - d) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;
            
            ans = ans * 10 + d;
            i++;
        }
        
        return ans * sign;
    }
};

/*
we traverse the string as per the rules until we reach the number to be extracted.

checking for overflow without using long datatype:
    - in each iteration, we update the answer as: ans = ans * 10 + d
    - we need to check if ans * 10 + d overflows, that is
        - ans * 10 + d > INT_MAX (or)
        - ans > (INT_MAX - d) / 10
    - if this is the case, |final answer| > INT_MAX.
        - if sign is positive, we return INT_MAX.
        - if sign is negative, we return INT_MIN
          (since if |ans| >= INT_MAX, then ans <= INT_MIN).

time complexity: O(n)
space complexity: O(1)
*/