class Solution {
public:
    // partition array and return pivot index
    int partition(int lb, int ub, vector<pair<int, int>> &arr) {
        pair<int, int> pivot = arr[lb];
        
        int l = lb + 1, r = ub;
        while (l <= r) {
            if (arr[r] < pivot && arr[l] > pivot)
                swap(arr[l], arr[r]);
            if (arr[r] >= pivot)
                r--;
            if (arr[l] <= pivot)
                l++;
        }
        
        // place pivot in correct position and return pivot index
        swap(arr[lb], arr[r]);
        return r;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        // dist, index of point
        vector<pair<int, int>> dists;
        
        for (int i=0; i<n; i++) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            dists.push_back({dist, i});
        }
        
        // find kth smallest element of dists array
        int lb = 0, ub = n-1;
        while (lb <= ub) {
            int pivot_idx = partition(lb, ub, dists);
            
            // k'th smallest element found
            if (pivot_idx == k-1)
                break;
            if (pivot_idx > k-1)
                ub = pivot_idx - 1;
            else
                lb = pivot_idx + 1;
        }
        
        // find k smallest points
        vector<vector<int>> ans;
        for (int i=0; i<k; i++)
            ans.push_back(points[dists[i].second]);
        
        return ans;
    }
};

/*
we create a distances array which stores the distances of each point from the origin.
we need to find the k'th smallest element in this array.

we need to find the k-1'th element in the sorted array.
we do this using the quick select algorithm.

the quick select algorithm allows us to find an element at a particular
index in the sorted array in O(n) time on average.
    
the quick select algorithm is as follows:
    - partition the array.
    - if the pivot index == k-1, we have found the k'th smallest element arr[k-1].
    - if the pivot index > k-1, partition the left half.
    - if the pivot index is < k-1, partition the right half.

when the pivot index is equal to k-1:
    - arr[k-1] is the k'th smallest element
    - arr[0] to arr[k-1] are the k smallest elements in the array.

time complexity: Average O(n), worst case O(n^2)
space compelxity: O(n)

https://leetcode.com/problems/k-closest-points-to-origin/
*/