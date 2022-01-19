class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lb = 0, ub = n-1;
        
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            
            // follow incline to the right
            if (mid < n-1 && nums[mid] < nums[mid+1])
                lb = mid + 1;
            
            // follow incline to the left
            else if (mid > 0 && nums[mid] < nums[mid-1])
                ub = mid - 1;
            
            // peak found
            else
                return mid;
        }
        
        // peak not found; should never reach here
        return -1;
    }
};

/*
we solve this question using binary search.
    - to find a peak, we move in the direction of increasing incline.
    - if there is no increasing incline on either side, then the current
      element is a peak.

at the current position mid:
    - if there is a increasing incline to the right (arr[mid+1] > arr[mid]), 
      search in the right half.
    - if there is a increasing incline to the left (arr[mid+1] > arr[mid]),
      search in the left half.
    - else, the current position is the required peak.
    
- nums[-1] = -inf means that there is a decreasing incline 
  to the left of index 0.
- nums[n] = -inf means that there is a decreasing incline 
  to the right of index n-1.
- the above 2 constraints mean that a peak will always exist.

- we can only use binary search if there is an incline on either side of mid, 
  that is, nums[i] != nums[i+1].
- in the case of a straight line, we cannot decide whether to go left or right.

time complexity: O(log n)
space complexity: O(1)
*/