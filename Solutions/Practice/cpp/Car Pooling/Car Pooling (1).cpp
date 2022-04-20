class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // timestamp -> number of passengers changed at that time
        // sorted in increasing order of timestamps
        map<int, int> passenger_delta;
        
        for (auto &trip : trips) {
            // passengers get on at source
            passenger_delta[trip[1]] += trip[0];
            // passengers leave at destination
            passenger_delta[trip[2]] -= trip[0];
        }
        
        // accumulate number of passengers
        int num_passengers = 0;
        for (auto &[timestamp, delta] : passenger_delta) {
            num_passengers += delta;
            
            // if num passengers at timestamp exceeds capacity
            if (num_passengers > capacity)
                return false;
        }
        
        return true;
    }
};

/*
we need to check at every timestamp from start to end
whether the number of passengers exceeds the capacity of the car.

at each timestamp (start time or end time), we find the delta (change) in
the number of passengers in the car.
    - at each source, we add the number of passengers who get on.
    - at each destination, we subtract the number of passengers who get off.

we then iterate over all timestamps in ascending order and accumulate the 
number of passengers in the car using these delta values.
if at any timestamp, the number of passengers exceeds the capacity of the car,
we return false.

time complexity: O(nlogn)
space complexity: O(n)

https://leetcode.com/problems/car-pooling/
*/