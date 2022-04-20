class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        out = []
        
        # find position to insert interval
        i = 0
        while i < n and intervals[i][0] < newInterval[0]:
            out.append(intervals[i])
            i += 1
        
        # merge with previous interval if necessary
        if out and newInterval[0] <= out[-1][1]:
            merged = [out[-1][0], max(out[-1][1], newInterval[1])]
            out.pop()
        else:
            merged = newInterval
        
        # merge intervals starting at i
        while i < n:
            if intervals[i][0] <= merged[1]:
                merged[1] = max(merged[1], intervals[i][1])
                i += 1
            else:
                break
        
        out.append(merged)
        
        # append remaining intervals
        while i < n:
            out.append(intervals[i])
            i += 1
        
        return out
        
"""
single pass algorithm:
    - append all intervals to the left of the current interval
    - merge new interval with its previous and next intervals
    - append remaining intervals

time complexity: O(n)
space complexity: O(1)
"""