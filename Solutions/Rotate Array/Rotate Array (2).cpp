class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        // counts number of changes made
        int count = 0;
        
        int i = n-1;
        while (count < n) {
            // initial position and value
            int start = i;
            int val = nums[start];
            
            // rotate
            do {
                int pos = (i - k + n) % n;
                nums[i] = nums[pos];
                i = pos;
                count++;
            } while (i != start);
            
            // update last index using stored value
            nums[(start + k) % n] = val;
            i--;
        }
    }
};

/*
at each index, we replace nums[i] with nums[i-k].

the algorithm is as follows:
    - at current index i, set nums[i] = nums[i-k].
    - update i = i-k.
    - continue this process until we reach the initial value of i.
        - if n % k != 0, the entire array will be rotated.
        - else, only a part of the array will be rotated.
            - we repeat this process starting from (i-1).
            - eventually, the entire array will be rotated.
    - we keep track of the number of indices changed.
      the entire array is rotated if we have updated all n indices.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/rotate-array/
*/