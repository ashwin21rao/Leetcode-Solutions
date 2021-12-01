class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // dp[i] = max amount which can be robbed starting at house i
        // we store only dp[i+1] and dp[i+2]
        vector<int> next_two = {nums[n-1], 0};
        
        for (int i=n-2; i>=0; i--) {
            int max_amount = max(nums[i] + next_two[1], next_two[0]);
            next_two[1] = next_two[0];
            next_two[0] = max_amount;
        }
        
        return next_two[0];
    }
};

/*
dp[i] = maximum amount which can be robbed starting at house i.
to find: dp[0]

at each house, we have 2 options: 
    - rob it and skip the next house.
    - do not rob it and go to the next house.
    - so, the recurrence relatino is: dp[i] = max(nums[i] + dp[i+2], dp[i+1])
    
space complexity optimization:
    - dp[i] depends only on dp[i+1] and dp[i+2].
    - so, we can store only these 2 values and not the entire dp array.
    - this improves space complexity from O(n) to O(1)

time complexity: O(n)
space complexity: O(1)
*/