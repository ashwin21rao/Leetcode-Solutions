class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int l = 0, r = people.size() - 1;
        int boats = 0;
        
        while (l <= r) {
            if (people[l] + people[r] <= limit)
                l++;
            
            r--;
            boats++;
        }
        
        return boats;
    }
};

/*
- sort the people.
- greedily choose 2 people at a time, pairing the largest
  weight with the smallest.
- if both people cannot fit in a boat, add only the 
  heavier one. 

time complexity: O(nlogn)
space complexity: O(1)

https://leetcode.com/problems/boats-to-save-people/
*/