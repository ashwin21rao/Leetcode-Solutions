class Solution {
public:
    double myPow(double x, int n) {
        int sign = n >= 0 ? 1 : -1;
        n = abs(n);
        
        // binary exponentiation to find x^n
        double ans = 1;
        while (n > 0) {
            if (n % 2 != 0)
                ans = ans * x;
            
            x = x * x;
            n /= 2;
        }
        
        return sign == 1 ? ans : 1 / ans;
    }
};

/*
we use binary exponentiation to find x^n in log(n) time.

time complexity: O(log n)
space complexity: O(1)

https://leetcode.com/problems/powx-n/
*/