class Solution {
public:
    // partitions array and returns pivot index
    int partition(int lb, int ub, vector<int> &nums) {
        int pivot = nums[lb];
        int l = lb + 1, r = ub;
        
        while (l <= r) {
            if (nums[r] < pivot && nums[l] > pivot)
                swap(nums[l], nums[r]);
            if (nums[r] >= pivot)
                r--;
            if (nums[l] <= pivot)
                l++;
        }
        
        // place pivot in correct position and return pivot index
        swap(nums[lb], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        int lb = 0, ub = n-1;
        while (lb <= ub) {
            int pivot_idx = partition(lb, ub, nums);
            
            // k'th largest element found
            if (pivot_idx == n-k)
                break;
            if (pivot_idx > n-k)
                ub = pivot_idx - 1;
            else
                lb = pivot_idx + 1;
        }
        
        return nums[n-k];
    }
};

/*
we need to find the n-k'th element in the sorted array.
we do this using the quick select algorithm.

the quick select algorithm allows us to find an element at a particular
index in the sorted array in O(n) time on average.

the quick select algorithm is as follows:
    - partition the array.
    - if the pivot index == n-k, we have found the k'th largest element arr[n-k].
    - if the pivot index > n-k, partition the left half.
    - if the pivot index is < n-k, partition the right half.

time complexity: Average O(n), worst case O(n^2)
space complexity: O(n)

https://leetcode.com/problems/kth-largest-element-in-an-array/
*/