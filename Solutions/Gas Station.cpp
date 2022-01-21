class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int capacity = 0;
        int ans = 0;
        
        // search for a station which takes us to position 0
        for (int i=0; i<n; i++) {
            capacity += gas[i];
            
            // if we can go to next station
            if (capacity >= cost[i])
                capacity -= cost[i];
            // start from next station
            else {
                capacity = 0;
                ans = i + 1;
            }
        }
        
        // check if we can go from 0 to the chosen station
        for (int i=0; i<ans; i++) {
            capacity += gas[i];
            
            // if we cannot go to the next station
            if (capacity < cost[i])
                return -1;
        
            capacity -= cost[i];
        }
        
        return ans;
    }
};

/*
this solution uses 2 passes.
we maintain the current capacity of the gas tank at each index.

initially, we start at station 0.
at each index, we check of there is enough gas to take us to the next station.
    - if so, we go to the next station.
    - else, this means that all gas stations from the starting station
      to the current station cannot be the answer. 
    - this is because at each intermediate station, we have >= gas in the tank 
      than if we started at that station.
    - the next possible answer is i+1. we start from i+1 with an empty tank.

after the first pass, we are back to position 0 with some gas in the tank.
in the second pass, we check if we can go from 0 to the chosen
station with this amount of gas.
    - if we can, then we can complete a full circle.
    - else, it is impossible.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/gas-station/submissions/
*/