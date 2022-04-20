class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        
        // stores the end times of currently ongoing meetings
        priority_queue<int, vector<int>, greater<>> end_times;
        
        for (auto &interval : intervals) {
            // pop all meetings which have ended
            while (!end_times.empty() && end_times.top() <= interval[0])
                end_times.pop();
            
            // push current meeting into priority queue
            end_times.push(interval[1]);
            
            // number of currently ongoing meetings
            ans = max(ans, (int)end_times.size());
        }
        
        return ans;
    }
};

/*
sort the intervals in ascending order of start times.

- we maintain a priority queue which stores in ascending order
  the end times of all currently ongoing meetings.

for the current meeting:
    - pop all meetings which have ended already.
    - that is, pop all meetings from the priority queue with end time 
      less than the start time of the current meeting.
    - push the current meeting into the queue.
    - hence, the size of the queue is the total number of currently
      ongoing meetings. this is the number of meeting rooms needed
      at the current instant.

time complexity: O(nlogn)
space complexity: O(n)

https://leetcode.com/problems/meeting-rooms-ii/
*/