class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // duration % 60 -> frequency
        unordered_map<int, int> durations;
        int count = 0;
        
        for (int &duration : time) {
            duration %= 60;
            
            // case 1 (b == 0, k == 0)
            if (duration == 0 && durations.find(0) != durations.end())
                count += durations[0];
            // case 2 (b != 0, k == 60)
            else if (durations.find(60 - duration) != durations.end())
                count += durations[60 - duration];
            
            durations[duration]++;
        }
        
        return count;
    }
};

/*
this question is similar to 2sum.
instead of finding if a pair with given sum exists, we need to count all pairs with the given sum.
    - for this, we maintain a hashmap which maps each number to its frequency so far.
    - for the current number num, we add frequency[sum - num] to the answer.

we need to count all pairs (a, b) such that (a + b) % 60 = 0
    - (a + b) % 60 = 0
    - (a % 60 + b % 60) % 60 = 0
    - a % 60 + b % 60 = 60k
    - since 0 <= a % 60 and b % 60 <= 59, k can be either 0 or 1. 

hence, we need to count all pairs (a, b) such that a % 60 + b % 60 = 60k (k = 0 or 1)
we maintain a hashmap which maps duration % 60 to its frequency so far.

1) k = 0
    - a % 60 + b % 60 = 0
    - this is possible only when b = 0.
    - we update the answer as count += frequency[0]
2) k = 60
    - a % 60 + b % 60 = 60
    - this is possible when b != 0.
    - we update the answer as count += frequency[60 - b % 60]

time complexity: O(n)
space complexity: O(60) = O(1) since the size of the hashmap is at most 60.

https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/