class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        indices = {}
        
        start = 0
        max_len = 0
        
        for i in range(len(s)):
            # character found previously in substring
            if s[i] in indices and indices[s[i]] >= start:
                # substring of greater length found
                max_len = max(max_len, i - start)
                
                # move sliding window
                start = indices[s[i]] + 1
            
            indices[s[i]] = i
        
        return max(max_len, len(s) - start)

"""
- we use a sliding window.
- when we come across a character previously seen in the 
  current sliding window:
    - we have found a substring with no repeating characters.
    - we move the left pointer of the window to the index
      after the previous occurrence of the character.

time complexity: O(n)
space complexity: O(26) = O(1)
"""