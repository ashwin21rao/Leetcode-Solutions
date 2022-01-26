/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    // comparator function (static because inside class)
    static bool compare(pair<Interval, int> i1, pair<Interval, int> i2) {    
        // condition reversed because we want a min-heap
        return i1.first.start > i2.first.start;
    }
    
    // merge k sorted lists of intervals in schedule
    vector<Interval> mergeKSortedLists(vector<vector<Interval>> schedule) {
        int k = schedule.size();
        vector<Interval> merged;
        
        // indices into each list
        vector<int> indices(k, 0);
        
        // insert all starting elements of each list into priority queue
        // {interval, list number}
        priority_queue<pair<Interval, int>, vector<pair<Interval, int>>, decltype(&Solution::compare)> pq(compare);
        for (int i=0; i<k; i++)
            pq.push({schedule[i][0], i});
        
        // merge k sorted schedules
        while (!pq.empty()) {
            auto [interval, list_num] = pq.top();
            pq.pop();
            
            merged.push_back(interval);
            indices[list_num]++;
            if (indices[list_num] < schedule[list_num].size())
                pq.push({schedule[list_num][indices[list_num]], list_num});
        }
        
        return merged;
    }
    
    // merge intervals
    vector<Interval> mergeIntervals(vector<Interval> intervals) {        
        vector<Interval> out;
        Interval merged(intervals[0].start, intervals[0].end);
        
        for (auto &interval : intervals) {
            // overlap occurs
            if (interval.start <= merged.end)
                merged.end = max(merged.end, interval.end);
            else {
                out.push_back(merged);
                merged = interval;
            }
        }
        
        out.push_back(merged);
        return out;
    }
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {        
        vector<Interval> intervals = mergeIntervals(mergeKSortedLists(schedule));
        
        int n = intervals.size();
        vector<Interval> out;

        // find all gaps between sorted intervals
        for (int i=0; i<n-1; i++) {
            Interval interval(intervals[i].end, intervals[i+1].start);
            out.push_back(interval);
        }
        
        return out;
    }
};

/*
we are given k sorted lists of Intervals (one for each employee).

- merge k sorted lists (such that the merged list is also sorted).
    time complexity: O(nlogk)
    
- merge intervals in this sorted list.
    time complexity: O(nk)

- find all gaps between the intervals after merging.
    time complexity: O(nk)

- the list of these gaps is the required answer.

time complexity: O(nk)
space complexity: O(nk)

https://leetcode.com/problems/employee-free-time/
*/