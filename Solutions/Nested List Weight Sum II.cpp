/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    void findDepths(vector<NestedInteger> &nestedList, int depth, int &maxDepth,
                    int &sum1, int &sum2) {
        
        maxDepth = max(maxDepth, depth);
        
        for (auto &list : nestedList) {
            // accumulate sum1 and sum2
            if (list.isInteger()) {
                int val = list.getInteger();
                sum1 += val;
                sum2 += val * (1 - depth);
            }
            // recurse
            else
                findDepths(list.getList(), depth + 1, maxDepth, sum1, sum2);
        }
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 0;
        int sum1 = 0, sum2 = 0;
        findDepths(nestedList, 1, maxDepth, sum1, sum2);
        
        return maxDepth * sum1 + sum2;        
    }
};

/*
we need to find the following quantity:

summation over all integers of: integer * (maxDepth - depth + 1)
= maxDepth * (sum of all integers) + summation over all integers of: (integer * (depth + 1))
= maxDepth * sum1 + sum2

we find the values of maxDepth, sum1 and sum2 directly during recursion (dfs).
- maxDepth is the maximum depth of a node in the recursion tree
- if the current nestedList is an integer, accumulate in sum1 and sum2
- else, recurse for this list (and increase depth by 1)

time complexity: O(V + E) = O(n) 
    where n is the number of nested lists + number of integers 
space complexity: O(h) where h is the depth of the recursion stack

https://leetcode.com/problems/nested-list-weight-sum-ii/
*/