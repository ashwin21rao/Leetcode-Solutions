class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        int ans = 0;
        
        // set of unique characters in current window
        unordered_set<char> hash;
        
        int l = 0;
        for (int i=0; i<n; i++) {
            // current character is seen previously
            if (hash.find(str[i]) != hash.end()) {
                // remove all characters upto previous occurrence of str[i]
                while (true) {
                    hash.erase(str[l]);
                    
                    if (str[l++] == str[i])
                        break;
                }
            }
            
            // add current character to window
            hash.insert(str[i]);
            
            // compare length of current window
            ans = max(ans, i - l + 1);
        }
        
        return ans;
    }
};

/*
- we maintain 2 pointers which point to the beginning and end
  of the current window: l and r.
- we store a set of characters in the current window.

there are 2 cases at the current index r:

1) if the current character str[r] is not present in the window:
    - add it to the window.
    - compare the length of the current window to the maximum 
     length seen so far.

2) if the current character str[r] is already present in the window,
   we need to remove its previous occurrence to get rid of the repetition.
    - increment the left pointer and remove all characters from the window
      until we reach the previous occurrence of str[r].
    - add the current character to the window.

time complexity: O(n)
space complexity: O(min(n, 26)) = O(1)
    since there are 26 characters, the max size of the window is 26.

https://leetcode.com/problems/longest-substring-without-repeating-characters
*/