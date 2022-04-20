class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // overshoot target
        int count = 0;
        while (startValue < target) {
            count++;
            startValue *= 2;
        }
        
        // amount overshot
        int overshot = startValue - target;
        
        // reduce overshot amount to zero
        int power = count;
        while (overshot > 0) {
            // current power of 2 under consideration
            int val = pow(2, power);
            power--;
            
            // subtract multiple of current power of 2
            count += overshot / val;
            overshot -= (overshot / val) * val;
        }
        
        return count;
    }
};

/*
- multiply the start value by 2 until we overshoot the target.
- we need to reduce the amount overshot to 0.
- this is done by subtracting 1s at certain positions.

- after subtracting a 1, we can multiply the result by 2. 
  overall, this results in subtracting a power of 2 from the final answer.

- if we multiplied startValue by 2 'count' times before overshooting:
    - the possible values we can subtract from the final answer 
      (by subtracting a 1 somewhere) are 2^0, 2^1, ..., 2^count.
    - to minimize the number of subtractions needed, we first subtract 
      largest powers of 2.

- the final answer is the number of initial multiplications + the number
  of subtractions to make the overshot amount 0.

time complexity: O(log(target - startValue))
space complexity: O(1)

https://leetcode.com/problems/broken-calculator/
*/