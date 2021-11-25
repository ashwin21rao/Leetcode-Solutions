class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lb = 0, ub = n-1;
        
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            
            // element found
            if (mid == 0 || mid == n-1)
                return nums[mid];
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            
            // go right or left
            if (nums[mid+1] != nums[mid]) {
                if ((ub - mid) % 2 == 0)
                    ub = mid - 2;
                else
                    lb = mid + 1;
            }
            else {
                if ((mid - lb) % 2 == 0)
                    lb = mid + 2;
                else
                    ub = mid - 1;
            }
        }
        
        // element not found; should not reach this point
        return -1;
    }
};

/*
we solve this problem using binary search.

- if arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1], then we have found the answer.
- else, we remove the pair of the element in the middle.
    - if arr[mid+1] != arr[mid]:
        - if the size of the upper half is even, the required element cannot be there.
          so, we search in (lb, mid-2).
        - else, we search in (mid+1, ub).
    - if arr[mid-1] != arr[mid]:
        - if the size of the lower half is even, the required element cannot be there.
          so, we search in (mid+2, ub).
        - else, we search in (lb, mid-1).
        
time complexity: O(log n)
space complexity: O(1)

https://leetcode.com/problems/single-element-in-a-sorted-array/
*/