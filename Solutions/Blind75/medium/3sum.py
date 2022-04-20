class Solution:
    def twoSum(self, start, nums, target):
        n = len(nums)
        l = start
        r = n - 1
        
        out = []
        while l < r:
            sum_val = nums[l] + nums[r]
            
            if sum_val < target or (l > start and nums[l] == nums[l-1]):
                l += 1
            elif sum_val > target or (r < n-1 and nums[r] == nums[r+1]):
                r -= 1
            else:
                out.append([nums[l], nums[r]])
                l += 1
                r -= 1
        
        return out
    
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        
        n = len(nums)
        out = []
        
        for i in range(n):
            if i == 0 or nums[i] != nums[i-1]:
                # find 2 numbers adding up to -nums[i]
                pairs = self.twoSum(i + 1, nums, -nums[i])
                out.extend([[nums[i], *p] for p in pairs if p])                
        
        return out

"""
- sort the array.
- for each element, find if 2 numbers add up to target
  in the remaining part of the array (2sum with 2 pointers).
- skip duplicate elements during iteration to prevent duplicates.

time complexity: O(nlogn)
space complexity: O(n)
"""