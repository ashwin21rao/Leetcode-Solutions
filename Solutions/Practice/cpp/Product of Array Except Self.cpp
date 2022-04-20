class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // find cumulative left product
        int prod = 1;
        for (int i=0; i<n-1; i++) {
            prod *= nums[i];
            ans[i+1] = prod;
        }
        
        // find cumulative right product
        prod = 1;
        for (int i=n-1; i>0; i--) {
            prod *= nums[i];
            ans[i-1] *= prod;
        }
        
        return ans;
    }
};

/*
ans[i] = cumulative product from the left (0 to i-1) * 
         cumulative product from the right (n-1 to i+1)

space complexity optimization:
    - we first accumulate the left cumulative products in ans.
    - we then multiply these by the right cumulative products.
    - hence, we do not use any additional space to store the products.
    
time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/product-of-array-except-self/
*/