# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        # find possible celebrity
        celeb = 0
        for i in range(1, n):
            if knows(celeb, i):
                celeb = i
        
        # verify if celebrity knows no one
        for i in range(celeb):
            if knows(celeb, i):
                return -1
        
        # verify if everyone knows celebrity
        for i in range(n):
            if i != celeb and not knows(i, celeb):
                return -1
        
        return celeb

"""
Consider two nodes A and B.
  - If A knows B, A is not a celebrity.
  - If A does not know B, B is not a celebrity.

- Hence, iterating from 0 to n-1, we can rule out
  all nodes as celebrities, except a single candidate.
- We then check if this node is a celebrity.

A maximum of 3n API calls are made (worst case: celebrity = n-1).

time complexity: O(n)
space complexity: O(1)
"""