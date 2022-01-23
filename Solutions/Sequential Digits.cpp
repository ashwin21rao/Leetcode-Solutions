class Solution {
public:
    int findNumberOfDigits(int num) {
        int d = 0;
        while (num > 0) {
            d++;
            num /= 10;
        }
        return d;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        int d1 = findNumberOfDigits(low);
        int d2 = findNumberOfDigits(high);
        
        // initialize variables
        int start = 0, add = 0;
        for (int i=1; i<d1; i++) {
            start = start * 10 + i;
            add = add * 10 + 1;
        }
        
        // loop over all number of digits
        for (int d=d1; d<=d2; d++) {
            start = start * 10 + d;
            add = add * 10 + 1;
            
            // loop over all sequential numbers with d digits
            int num = start;
            for (int i=0; i<10-d; i++) {
                if (num >= low && num <= high)
                    ans.push_back(num);
                
                num += add;
            }
        }
        
        return ans;
    }
};

/*
for a certain number of digits d, there are (10-d) 
sequential numbers.
    - each sequential number differs by 11...1 (d times)
    - the first sequential number is 12...d
    - hence, these values for a particular d can be found from
      their values from (d-1)

d1 = number of digits in low
d2 = number of digits in high
the algorithm is as follows:

initialize variables:
    - start = 12...(d1-1)
    - add = 11...(d1-1)
    
- iterate over all number of digits d from d1 to d2
    - get current start (starting sequential number) and 
      add (difference between consecutive sequential numbers).
    - for each d, iterate over all sequential numbers with d digits.
    
time complexity: O(d * (10-d)) = O(1)
space complexity: O(1)

https://leetcode.com/problems/sequential-digits/
*/