class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // node -> in degree - out degree
        vector<int> degree(n+1);
        
        for (auto &t : trust) {
            degree[t[0]]--;
            degree[t[1]]++;
        }
        
        // search for node with in degree = n-1 and out degree = 0
        for (int i=1; i<=n; i++) {
            if (degree[i] == n-1)
                return i;
        }
        return -1;
    }
};

/*
consider each person as a node.
if a person 'A' trusts 'B', there is a directed edge from A to B

we need to find the node with in degree = n-1 and out degree 0.

space complexity optimization:
    - instead of storing the in degree and out degree of each node, 
      we store (in degree - out degree).
    - we need to find the node with (in degree - out degree) = n-1.
        - this is possible only for a node with in degree = n-1 and out degree = 0.
        - this is because maximum in degree = n-1 and minimum out degree = 0. 

E -> size of the trust array (number of edges)
time complexity: O(E + N)
space complexity: O(n)

https://leetcode.com/problems/find-the-town-judge/
*/