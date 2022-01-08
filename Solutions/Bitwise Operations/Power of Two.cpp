class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};

/*
there are 2 possible approaches using bitwise operations:

1) checking if x & (-x) == x:
    - x & (-x) keeps the rightmost set bit and sets all other bits to 0.
    - this is because -x is represented as the 2's complement of x (x' + 1).
    - if x is a power of 2, there is only 1 set bit. so, x & (-x) = x.

2) checking if x & (x-1) == 0:
    - x & (x-1) sets the leftmost set bit to 0.
    - if x is a power of 2, there is only 1 set bit. so, x & (-x) = 0.

the above two relations hold for both x > 0 and x < 0.

however, -x and (x-1) will cause overflow if x is -2^31.
to avoid this, we either: 
    - typecast x to long to prevent overflow
    - calculate the relations only on x > 0 since we know that 
      x <= 0 cannot be a power of 2.
    
time complexity: O(1)
space complexity: O(1)

https://leetcode.com/problems/power-of-two/
*/