class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // first string in sequence (starting with 'a') 
        // -> all strings belonging to sequence
        unordered_map<string, vector<string>> hash;
        
        for (string str : strings) {
            // shift string to make its first character 'a'
            int shift = str[0] - 'a';
            string shifted = str;
            
            for (char &ch : shifted) {
                ch -= shift;
                if (ch < 'a')
                    ch += 26;
            }
            
            // add string to hashmap
            hash[shifted].push_back(str);
        }
        
        // add groups to output
        vector<vector<string>> out;
        for (auto &[key, group] : hash)
            out.push_back(group);
        
        return out;
    }
};

/*
this problem is similar in idea to group anagrams.
we need to group all given strings into some number of groups.

we come up with a one-to-many hash function to map every string of a 
group to a specific key.

- all strings in a group belong to the same shifting sequence.
- for each string in a group, the first string of the sequence 
  (starting with 'a') is the same.
- we maintain an unordered map which maps the first string of a sequence
  (beginning with 'a') to all strings of that sequence present in the list.

n = number of strings
k = max length of string
time complexity: O(nk)
space complexity: O(nk)

https://leetcode.com/problems/group-shifted-strings/
*/