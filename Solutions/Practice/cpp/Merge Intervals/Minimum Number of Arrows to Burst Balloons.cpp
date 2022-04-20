class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        // upper bound of running intersection of intervals
        int ub = points[0][1];
        int count = 0;
        
        for (auto &point : points) {
            // current interval intersects previous interval
            if (point[0] <= ub)
                ub = min(ub, point[1]);
            // add previous group of intersecting intervals
            else {
                ub = point[1];
                count++;
            }
        }
        
        // consider last group
        return count + 1;
    }
};

/*
this question is similar to merge intervals.
    - in merge intervals, we find the running union of intervals.
    - here, we find the running intersection of intervals.
      each group of intersecting intervals can be burst by a single balloon.

- sort the intervals.
- we find the running intersection of intervals.
- when the current interval does not overlap with the running intersection:
    - increment the number of balloons to account for the previous group.
    - update the running intersection to be the current interval.

- two intervals overlap if:
    - interval2[0] <= interval1[1]
    - interval2[0] >= interval1[0]: this condition does not need to be checked
      since the intervals are already sorted by their first element.

time complexity: O(nlogn)
space complexity: O(1)

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/