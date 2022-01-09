class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort trips in ascending order of starting point
        sort(trips.begin(), trips.end(), [](vector<int> trip1, vector<int> trip2) {
            return trip1[1] < trip2[1];
        });
        
        // stores destinations: {dest, number of passengers}
        // in increasing order of destination
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dests;
        
        int cur_passengers = 0;
        for (auto &trip : trips) {
            // remove all passengers who reached destination before current start point
            while (!dests.empty() && dests.top().first <= trip[1]) {
                cur_passengers -= dests.top().second;
                dests.pop();
            }
            
            // no space in car
            if (cur_passengers + trip[0] > capacity)
                return false;
            
            // add passengers to car
            cur_passengers += trip[0];
            dests.push({trip[2], trip[0]});
        }
        
        return true;
    }
};

/*
this appraoch is similar to meeting rooms 2.

sort the trips in increasing order of start times.
at each start time, we check whether there is enough space in the car for that trip.

we maintain a priority queue which stores destinations of ongoing trips.
this is sorted in increasing order of destinations.

iterate over trips as follows:
    - remove all destinations from the queue which are before the start time 
      of the current trip.
    - check if there is enough space in the car for the current trip. 
      if not, return false.
    - else, add current destination to the priority queue.

time complexity: O(nlogn)
space complexity: O(n)

https://leetcode.com/problems/car-pooling/
*/