class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // stores sums of pairs of numbers in nums1 and nums2
        unordered_map<int, int> sums;
        
        for (int &num1 : nums1) {
            for (int &num2 : nums2)
                sums[num1 + num2]++;
        }
        
        // loop over sums of pairs of numbers in nums3 and nums4
        int count = 0;
        for (int &num3 : nums3) {
            for (int &num4 : nums4) {
                int sum = num3 + num4;
                
                if (sums.find(-sum) != sums.end())
                    count += sums[-sum];
            }
        }
        
        return count;
    }
};

/*
we need to find all tuples (i, j, k, l) such that:
    - nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0 (or)
    - nums1[i] + nums2[j] == -(nums3[k] + nums4[l])

- store all possible values of nums1[i] + nums2[j]
  (all sums of pairs of numbers in nums1 and nums2) 
  and their frequencies in a hashmap.
  
- loop over all values of nums3[k] + nums4[l].
  (all sums of pairs of numbers in nums3 and nums4) 

- if the negative of this sum occurs in the hashmap,
  we have found possible 4-tuple(s). add its frequency 
  to the answer.

time complexity: O(n^2)
space complexity: O(n^2)

Follow up: Generalized ksum II:
    - the logic is exactly the same but for k lists.
    - the hashmap conatins all sums of pairs of 
      the first k/2 lists.
    - we loop over all sums of pairs of 
      the last k/2 lists.
    - time complexity: O(n ^ (k/2))
    - space complexity: O(n ^ (k/2))

https://leetcode.com/problems/4sum-ii/
*/