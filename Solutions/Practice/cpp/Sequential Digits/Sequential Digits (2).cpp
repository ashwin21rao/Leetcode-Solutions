class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for (int i=1; i<=9; i++) {
            int num = 0;
            for (int j=i; j<=9; j++) {
                num = num * 10 + j;
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
we generate all sequential numbers in the following order:
    1, 12, 123, ...., 123456789
    2, 23, 234, ...., 23456789
and so on.
we then sort the answer.

time complexity: O(1)
space complexity: O(1)

https://leetcode.com/problems/sequential-digits/submissions/
*/