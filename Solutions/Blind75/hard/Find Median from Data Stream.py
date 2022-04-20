class MedianFinder:

    def __init__(self):
        self.pq1 = []  # max heap for first half
        self.pq2 = []  # min heap for second half

    def addNum(self, num: int) -> None:
        if len(self.pq1) == len(self.pq2):
            heappush(self.pq2, num)
            val = heappop(self.pq2)
            heappush(self.pq1, -val)
        else:
            heappush(self.pq1, -num)
            val = heappop(self.pq1)
            heappush(self.pq2, -val)

    def findMedian(self) -> float:
        if len(self.pq1) == len(self.pq2):
            return (-self.pq1[0] + self.pq2[0]) / 2
        
        return -self.pq1[0]

"""
we need to access the middle element of the sorted stream.
we maintain two priority queues:
    - a max-heap to store the first half: pq1
    - a min heap to store the second half: pq2
    - maintain len(pq1) >= len(pq2)
    - the top of pq1 and pq2 will be the middle elements
      of the stream so far.

inserting into stream: O(log n) time
  1) if len(pq1) == len(pq2)
        - insert into pq2
        - pop the smallest element from pq2 and insert
          into pq1 (maintains the length constraint).
  2) if len(pq1) > len(pq2):
        - insert into pq1
        - pop the largest element from pq1 and insert
          into pq2 (maintains the length constraint)
 
finding median: O(1) time
  1) if len(pq1) == len(pq2)
        - the stream is of even length
        - return the average of the 2 middle elements
          (pq1.top and pq2.top)
  2) if len(pq1) > len(pq2):
        - the stream is of odd length
        - return the middle element (top of pq1)
"""