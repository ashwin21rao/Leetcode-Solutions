class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        
        int i = 0;
        while (i < n) {
            // consume equal elements
            int j = i + 1;
            while (j < n && nums[j] == nums[i])
                j++;
            
            nums[pos] = nums[i];
            pos++;
            i = j;
        }
        
        // remove extra elements
        for (i=n-1; i>=pos; i--)
            nums.pop_back();
        
        return pos;
    }
};

/*
- we modify the list in place.
- we begin building the output list at the beginning of the input list.
- at any point in time, the size of the output is less than the size 
  of the input. hence, modifying the input list from the beginning will 
  not overwrite any info beyond the current index.

- consume all equal elements and add the element to the answer.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/