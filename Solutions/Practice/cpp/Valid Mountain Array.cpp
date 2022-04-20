class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        
        int n = arr.size();
        
        // check uphill slope
        int i = 0;
        while (i < n-1 && arr[i] < arr[i+1])
            i++;
        
        // no uphill or downhill slope exists
        if (i == 0 || i == n-1)
            return false;
        
        // check downhill slope
        while (i < n-1 && arr[i] > arr[i+1])
            i++;
        
        return i == n-1;
    }
};

/*
- we first go up the uphill slope and then down the 
  downhill slope.
- we should reach the end of the array after both slopes.
- if there is only an uphill or downhill but not both,
  it is not a mountain.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/valid-mountain-array/
*/