class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        
        // iterate over all numbers
        for (int &num : nums) {
            int size = subsets.size();
            
            // add num to all subsets
            for (int i=0; i<size; i++) {
                vector<int> subset = subsets[i];
                subset.push_back(num);
                subsets.push_back(subset);
            }
        }
        
        return subsets;
    }
};

/*
- we loop over all numbers.
- in each iteration, we generate the list of all subsets using
  all numbers upto that point.
- in the current iteration:
    - loop over all subsets of all previous numbers.
    - generate all new subsets contianing the current number by
      adding it to all existing subsets.
    - add the new subsets to the output.

time complexity: O(n * 2^n)
    - there are 2^n subsets.
    - it takes O(n) time to copy a subset to the output.

space complexity: O(n) to store each subset

https://leetcode.com/problems/subsets/
*/