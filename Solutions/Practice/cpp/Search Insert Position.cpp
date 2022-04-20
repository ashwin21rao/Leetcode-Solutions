class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = 0, ub = n-1;
        
        int ans = -1;
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
        
        return ans == -1 ? n : ans;
    }
};

/*
find the index of the least element >= target.

time complexity: O(nlogn)
space complexity: O(1)
*/