
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l1 = s.size();
        int l2 = p.size();
        vector<int> out;
        
        // character -> frequency
        unordered_map<char, int> p_freq;
        for (char &ch : p)
            p_freq[ch]++;
        
        // add first l2 letters of s
        unordered_map<char, int> freq;
        for (int i=0; i<l2; i++)
            freq[s[i]]++;
        
        if (freq == p_freq)
            out.push_back(0);
        
        // sliding window
        for (int i=l2; i<l1; i++) {
            // add current character to hashmap
            freq[s[i]]++;
            
            // remove character which went out of sliding window
            freq[s[i - l2]]--;
            if (freq[s[i - l2]] == 0)
                freq.erase(s[i - l2]);
            
            // include index start of sliding window
            if (freq == p_freq)
                out.push_back(i - l2 + 1);
        }
        
        return out;
    }
};

/*
- all anagrams of a string have the same frequency of characters.
- hence, a string is an anagram of the given string if it has the
  same frequency of all characters as the original string.

- we maintain a hashmap of the original string which maps
  each character to its frequency.
- we maintain another frequency hashmap for the current sliding
  window.

- we iterate over string s using a sliding window of size p.length().
  if the hashmap of the current window is equal to the hashmap of the
  given string, then the window is an anagram of the string.

time complexity: O(26n) = O(n)
space complexity: O(26) = O(1)

https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/