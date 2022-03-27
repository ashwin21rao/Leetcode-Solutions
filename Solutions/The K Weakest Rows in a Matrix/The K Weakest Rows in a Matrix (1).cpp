class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r = mat.size(), c = mat[0].size();

        // max heap priority queue
        // {number of 1s in row, row number}
        priority_queue<pair<int, int>> pq;
        
        for (int i=0; i<r; i++) {
            // find position of rightmost 1 using binary search
            int ones = lower_bound(mat[i].rbegin(), mat[i].rend(), 1) - mat[i].rend();
            
            pq.push({-ones, i});

            // pop largest if pq exceeds size k
            if (pq.size() > k)
                pq.pop();
        }
        
        // pop k smallest elements
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
for each row, find the number of 1s.
    - this can be done using binary search since it is sorted 
      in descending order.
    - time complexity: O(nlogm)
    
we need to sort rows by number of 1s and then by row number,
(in ascending order).
we then need to find the k smallest elements of this sorted array.

- this is done using a priority queue, since we need the
  k smallest elements in sorted order.
- we do not use quick select since it returns the k smallest
  elements in any order.
- time complexity: O(nlogk)

time complexity: O(nlogm) + O(nlogk) = O(n log(mk))
space complexity: O(k) for the priority queue

https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
*/