class Solution {
public:
    int extractNum(string s, int &i) {
        int len = s.size();
        
        int num = 0;
        while (i < len && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return num;
    }
    
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int i = 0, j = 0;
        
        while (i < len1 || j < len2) {
            // extract current revisions
            int revision1 = extractNum(version1, i);
            int revision2 = extractNum(version2, j);
            
            // skip "."
            i++, j++;
            
            // compare revisions
            if (revision1 > revision2)
                return 1;
            if (revision1 < revision2)
                return -1;
        }
        
        // versions are the same
        return 0;
    }
};

/*
- we iterate over both versions simultaneously and compare
  their revisions in order.
- in each iteration, extract the current revision of both 
  versions and compare them.

time complexity: O(n + m) since we loop over both strings
space complexity: O(1)

https://leetcode.com/problems/compare-version-numbers/
*/