class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> out;
        vector<int> merged = intervals[0];
        
        for (auto &interval : intervals) {
            // intervals overlap: merge them
            if (interval[0] <= merged[1])
                merged[1] = max(merged[1], interval[1]);
            else {
                out.push_back(merged);
                merged = interval;
            }
        }
        
        out.push_back(merged);
        return out;
    }
};

/*
sort the intervals.

- we find the running union of intervals.
- when the current interval does not overlap with the running union:
    - add the union to the answer.
    - update the running union to be the current interval.

- two intervals overlap if:
    - interval2[0] <= interval1[1]
    - interval2[0] >= interval1[0]: this condition does not need to be checked
      since the intervals are already sorted by their first element.
      
time complexity: O(nlogn)
space complexity: O(1)

https://leetcode.com/problems/merge-intervals/
*/