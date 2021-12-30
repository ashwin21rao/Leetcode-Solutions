class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 0, ans = 0;
        
        for (int i=0; i<k; i++) {
            // get current remainder from previous remainder
            rem = ((rem * (10 % k)) % k + 1) % k;
            ans++;
            
            // if remainder is 0 
            if (rem == 0)
                return ans;
        }
        
        // no such number exists
        return -1;
    }
};

/*
consider the example 11111 (n = 5):
    - 11111 = 1111 * 10 + 1
    - 11111 % k = ((1111 % k * 10 % k) + 1) % k
    - remainder = ((prev_remainder * (10 % k)) + 1) % k 
    - hence, we can get the current remainder (for n) from the previous remainder (for n-1).

- we check remainders for increasing n.
- if the remainder at any point is 0, we have fonud the required number.
- if a remainder repeats before we get a 0 remainder:
    - it forms a cycle in remainders.
    - in this case, it is impossible to get a 0 remainder.

- we run a loop from 0 to k and find remainders in each case.
    - if remainder is 0, we have found the required number.
    - if any of the first k remainders are never 0, 
        - the (k+1)th remainder must be a repeat.
        - this is due to the pigeonhole principle, since there are only 
          k possible remainders (0 to k-1).

time complexity: O(k)
space complexity: O(1)
*/