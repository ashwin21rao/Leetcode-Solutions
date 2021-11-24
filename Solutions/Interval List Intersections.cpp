class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, 
                                             vector<vector<int>>& list2) {
        vector<vector<int>> out;
        
        int n = list1.size(), m = list2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            // find intersection
            int lb = max(list1[i][0], list2[j][0]);
            int ub = min(list1[i][1], list2[j][1]);
            
            if (lb <= ub)
                out.push_back({lb, ub});
            
            // increment pointers
            if (list1[i][1] > list2[j][1]) j++;
            else i++;
        }
        
        return out;
    }
};

/*
2 pointer approach, one for each list:
    - check if list1[i] and list2[j] overlap.
    - if list1[i][1] < list2[i][1], increment i. else increment j. 

intersection of 2 intervals:
    - {lb, ub} = {max of lower bounds, min of upper bounds}
    - if lb <= ub, then they intersect.

time complexity: O(n)
space complexity: O(1)
*/