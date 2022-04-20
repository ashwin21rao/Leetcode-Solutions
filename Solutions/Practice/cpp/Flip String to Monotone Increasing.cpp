class Solution {
public:
    int minFlipsMonoIncr(string str) {
        int ones = count(str.begin(), str.end(), '1');
        int n = str.size();
        
        // number of ones to the left of current index and including it
        int left_ones = 0;
        int min_flips = n;
        
        for (int i=0; i<n; i++) {
            if (str[i] == '1')
                left_ones++;
            
            // number of ones to the right of current index and excluding it
            int right_zeros = (n - i - 1) - (ones - left_ones);
            min_flips = min(min_flips, left_ones + right_zeros);
        }
        
        // handle the case of flipping all bit to ones
        return min(min_flips, n - ones);
    }
};

/*
we need to find the minimum flips to make the string of the following form:
for some index i:
    - all characters to the left of i are 0.
    - all characters to the right of i are 1.

we split the string at a given index.
the number of flips to make the string monotone increasing at this index
    = (number of ones on the left) + (number of zeros on the right).

we find the index which gives us the minimum flips.

O(n) space solution:
maintain an array which stores for each index:
    - the number of ones to the left
    - the number of zeros to the right
    
Space optimization: O(1) space solution
- we can find the number of ones to the left of an index while iterating over the array.
- the number of zeros to the right of the index 
    = (total elements to the right - number of ones to the right)
    = (total elements to the right) - (total ones in the string - number of ones to the left)

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/flip-string-to-monotone-increasing/
*/