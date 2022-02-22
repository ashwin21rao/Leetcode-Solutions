class Solution {
public:
    int fixedPoint(vector<int>& nums) {
        int lb = 0, ub = nums.size() - 1;
        
        int ans = -1;
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            
            // possible index found
            if (nums[mid] == mid) {
                ans = mid;
                ub = mid - 1;
            }
            // go to the left
            else if (nums[mid] > mid)
                ub = mid - 1;
            // go to the right
            else
                lb = mid + 1;
        }
        
        return ans;
    }
};

/*
- the array is sorted in increasing order
- there are NO DUPLICATES.

we use binary search to search for the required index.

if arr[mid] == mid:
    - we have found a possible index.
    - we go left to search for a smaller possible answer.
if arr[mid] > mid:
    - no index to the right can satisfy arr[i] = i.
    - for all indices on the right, arr[i] > i (since there are no duplicates).
    - so, we go to the left.
if arr[mid] < mid:
    - no index to the left can satisfy arr[i] = i.
    - for all indices on the right, arr[i] < i (since there are no duplicates).

time complexity: O(log n)
space complexity: O(1)

https://leetcode.com/problems/fixed-point/
*/