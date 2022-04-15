"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""

class Solution:    
    def mergeKSorted(self, intervals):
        k = len(intervals)
        pointers = [0] * k
        
        # push into priority queue
        pq = []
        for i in range(k):
            heapq.heappush(pq, (intervals[i][0], i))
        
        merged = []
        while pq:
            interval, list_num = heapq.heappop(pq)
            merged.append(interval)
            
            # move pointer forward
            pointers[list_num] += 1
            if pointers[list_num] < len(intervals[list_num]):
                heapq.heappush(pq, (intervals[list_num][pointers[list_num]], list_num))
        
        return merged
    
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        schedule = [[[interval.start, interval.end] for interval in intervals] for intervals in schedule]
        intervals = self.mergeKSorted(schedule)
        
        # merge intervals
        out = []
        merged = intervals[0]
        
        for interval in intervals:
            # overlap occurs
            if interval[0] <= merged[1]:
                merged[1] = max(merged[1], interval[1])
            else:
                out.append(Interval(merged[1], interval[0]))
                merged = interval
        
        return out
        
"""
merge sorted lists of intervals for each employee
merge intervals of this new list

k = number of employees
n = total number of intervals

time complexity: O(nlogk + n)
space complexity: O(n)
"""