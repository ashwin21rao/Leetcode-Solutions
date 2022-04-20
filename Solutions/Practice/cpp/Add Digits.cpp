class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};

/*
- a number is divisible by 9 if the sum of its digits is 
  divisible by 9. this means:
- num mod 9 = (d0 + d1 + d2 + ... + dk) mod 9

CASE 1: num % 9 == 0
    - in each iteration, the sum of digits is divisible by 9.
    - eventually, we reach 9 as the single digit.

CASE 2: num % 9 != 0
    - in the first iteration, sum of digits = n % 9
    - in subsequent iterations, we repeatedly find (sum % 9).
    - this has no effect since the previous sum is already between 
      0 and 8.
    - hence, the single digit is n % 9.

time complexity: O(1)
space complexity: O(1)

https://leetcode.com/problems/add-digits/
*/