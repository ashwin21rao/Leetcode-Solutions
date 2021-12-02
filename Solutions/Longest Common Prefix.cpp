class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        
        for (string &str : strs) {            
            // find common prefix between str and previous prefix
            int i = 0;
            int n = str.size();
            while (i < n && str[i] == prefix[i])
                i++;
            
            // no common prefix
            if (i == 0) return "";
            
            prefix = str.substr(0, i);
        }
        
        return prefix;
    }
};

/*
we find the longest common prefix between consecutive pairs of strings.
in each iteration, we find the LCP between the current string and the previous prefix.
we continue this till we reach the end of the array.

time complexity: O(nL)
space complexity: O(1)
*/