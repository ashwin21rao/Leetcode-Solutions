class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int even = 0;
        
        for (int &pos : position) {
            if (pos % 2 == 0)
                even++;
        }
        
        return min(even, n - even);
    }
};

/*
we count the number of coins in even and odd positions.
- we can move coins in even positions to any other even position with 0 cost.
- we can move coins in odd positions to any other odd position with 0 cost.

- all even coins can be moved to an even position with 0 cost.
- all odd coins can be moved to an odd position with 0 cost.
- to minimize the cost, these positions are adjacent to each other.
- now, we either move all odd coins to the adjacent even position or all even
  coins to the adjacent odd position.
- hence, the required minimum cost is min(even_count, odd_count)

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
*/