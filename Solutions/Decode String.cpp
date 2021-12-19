class Solution {
public:
    string decodeString(string &str, int &i) {
        int n = str.size();
        string decoded = "";
        
        while (i < n && str[i] != ']') {            
            // if character is a letter, append it
            if (isalpha(str[i])) {
                decoded += str[i];
                i++;
            }
            else {
                // find number of repititions
                int num = 0;
                while (i < n && isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                i++;
                
                // append string obtained from recursion
                string res = decodeString(str, i);
                for (int j=0; j<num; j++)
                    decoded += res;
            }
        }
        i++;
        
        return decoded;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};

/*
a global pointer is maintained to keep track of the current index in the original 
string across all recursive calls.

we construct the decoded string as follows:
    - if we encounter a letter, append it directly.
    - if we encounter a digit,
        - find the number of repititions 'num'.
        - recurse for the string in square brackets and return this string.
        - append this string 'num' times to the answer.
    - the current recursion ends when we reach a closing ']' or the end of the string.

d = maximum integer in s
n = length of string

time complexity: O(nd) to append d times the string of length n.
space complexity: O(n) excluding output, to store the result of the recursion.

https://leetcode.com/problems/decode-string/
*/