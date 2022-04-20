class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        int ans = 0;
        
        // character -> most recent index
        unordered_map<char, int> hash;
        
        int l = 0;
        for (int i=0; i<n; i++) {
            // current character is seen previously and is in current window
            if (hash.find(str[i]) != hash.end() && hash[str[i]] >= l)
                l = hash[str[i]] + 1;
            
            // add current character to window
            hash[str[i]] = i;
            
            // compare length of current window
            ans = max(ans, i - l + 1);
        }
        
        return ans;
    }
};

/*
- we maintain 2 pointers which point to the beginning and end
  of the current window: l and r.
- we store a hashmap of characters seen so far and their 
  most recent index.

there are 2 cases at the current index r:

1) if the current character str[r] is not present in the window:
    - add it to the window.
    - compare the length of the current window to the maximum 
      length seen so far.

2) if the current character str[r] is already present in the window,
   we need to remove its previous occurrence to get rid of the repetition.
   hence, we set the left pointer to the index after the previous occurrence.

time complexity: O(n)
space complexity: O(min(n, 26)) = O(1)
    since there are 26 characters, the max size of the window is 26.

https://leetcode.com/problems/longest-substring-without-repeating-characters
*/