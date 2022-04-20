class Solution {
public:
    int findComplement(int num) {
        // find the position of the leftmost set bit
        int k = (int)log2(num);
        
        // XOR all positions from k to 0 with 1
        return num ^ ((1L << (k+1)) - 1);
    }
};

/*
- find the position of the leftmost set bit in the number (= k).
- we need to complement all bits to the right of this bit and including it.
- zeros to the right of this bit should remain unchanged.

- XORing a bit with 1 flips the bit.
- hence, we XOR every bit from 0 to k with 1.
- this number is obtained by (1 << (k+1)) - 1.

time complexity: O(1)
space complexity: O(1)

https://leetcode.com/problems/number-complement/
*/