class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        out = [1 for _ in range(n)]
        
        # left cumulative product
        product = 1
        for i in range(0, n-1):
            product *= nums[i]
            out[i+1] *= product
        
        # right cumulative product
        product = 1
        for i in range(n-1, 0, -1):
            product *= nums[i]
            out[i-1] *= product
        
        return out

"""
product except self at an index i = 
    left cumulative product(0, i-1) * 
    right cumulative product(i+1, n-1)

- calculate left and right cumulative products separately
- multiply them with the output array directly to use O(1)
  space.

time complexity: O(n)
space complexity: O(1) excluding the output
"""