class TimeMap:

    def __init__(self):
        # key -> (automatically sorted) list of (timestamp, value)
        self.time_map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.time_map[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        # find greatest timestamp <= given timestamp 
        idx = bisect_right(self.time_map[key], timestamp, key=lambda time: time[0]) - 1
        
        return "" if idx == -1 else self.time_map[key][idx][1]

"""
we map each key to a list of pairs of (timestamp, value)
each lists are automatically sprted by timestamp.

set():
    - time complexity: O(1)
    
get():
    - binary search for the greatest timestamp <= the query timestamp
    - time complexity: O(log n)
"""