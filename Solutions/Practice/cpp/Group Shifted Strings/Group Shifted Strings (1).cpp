class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // string -> frequency
        unordered_map<string, int> hash;
        for (string &str : strings)
            hash[str]++;
        
        vector<vector<string>> out;
        for (string &str : strings) {
            // string already added to answer
            if (hash[str] == -1)
                continue;
            
            vector<string> group;
            
            // check all possible shifts
            for (int i=0; i<26; i++) {
                // shift characters
                for (char &ch : str) {
                    ch++;
                    if (ch > 'z')
                        ch = 'a';
                }
                
                // check if shifted string exists
                if (hash.find(str) != hash.end()) {
                    // add all occurrences of string to group
                    for (int j=0; j<hash[str]; j++)
                        group.push_back(str);
                    
                    // mark string as visited
                    hash[str] = -1;
                }
            }
            
            // add group to answer
            out.push_back(group);
        }
        
        return out;
    }
};

/*
we maintain a hashmap which maps each string to its frequency.

- for each string, we check all 26 sequences which can be formed
  by shifting the string.
- if a sequence is found, add it to the current group and mark it
  as visited.

n = number of strings
k = maximum length of string
time complexity: O(26 * n * k) = O(nk)
space complexity: O(nk)

https://leetcode.com/problems/group-shifted-strings/
*/