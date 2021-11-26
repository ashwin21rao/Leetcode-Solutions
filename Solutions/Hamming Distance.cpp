class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y;
        int ans = 0;
        
        while (num > 0) {
            ans += (num & 1);
            num >>= 1;
        }
        
        return ans;
    }
};

/*
compute the XOR of the numbers.
count the number of 1s in the binary representation of this number.

time complexity: O(log n)
space complexity: O(1)
*/