class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> out;
        int min_diff = INT_MAX;
        
        for (int i=1; i<n; i++) {
            if (arr[i] - arr[i-1] < min_diff) {
                min_diff = arr[i] - arr[i-1];
                out = {{arr[i-1], arr[i]}};
            }
            else if (arr[i] - arr[i-1] == min_diff)
                out.push_back({arr[i-1], arr[i]});
        }
        
        return out;
    }
};

/*
- sort the array.
- the pairs with minimum absolute difference will be consecutive in the sorted array.
- loop over the array as folows:
    - for each consecutive pair, find its difference.
    - if this difference is less than the minimum difference seen so far,
      clear the ouput and add the current pair into it.
    - if this difference is equal to the minimum difference seen so far,
      add the current pair to the output.

time complexity: O(nlogn)
space complexity: O(n)

https://leetcode.com/problems/minimum-absolute-difference/
*/