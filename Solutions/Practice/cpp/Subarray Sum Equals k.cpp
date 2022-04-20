class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        
        // prefix sum -> frequency 
        unordered_map<int, int> sums;
        sums[0]++;
        
        int sum = 0;
        for (int &num : nums) {
            sum += num;
            if (sums.find(sum - k) != sums.end()) {
                count += sums[sum - k];
            }
            sums[sum]++;
        }
        
        return count;
    }
};

/*
for each prefix sum, search if (sum - k) has occurred before it
(similar to 2 sum)

time complexity: O(n)
space complexity: O(n)
*/