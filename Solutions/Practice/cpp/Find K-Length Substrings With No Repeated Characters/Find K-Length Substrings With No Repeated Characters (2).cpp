class Solution {
public:
    int numKLenSubstrNoRepeats(string str, int k) {
        int n = str.size();
        int count = 0;
        
        // character -> most recent index
        unordered_map<char, int> hash;
        
        int l = 0;
        for (int i=0; i<n; i++) {
            // if character is already seen and in current window
            if (hash.find(str[i]) != hash.end() && hash[str[i]] >= l)
                l = hash[str[i]] + 1;
            
            // insert current character into hash
            hash[str[i]] = i;
            
            // substring of length k found
            if (i - l + 1 == k) {
                count++;
                
                // slide window forward
                l++;
            }
        }
        
        return count;
    }
};

/*
this question is a variation of Longest Substring Without Repeating Characters.

- we maintain 2 pointers which point to the beginning and end
  of the current window: l and r.
- we store a hashmap of characters seen so far and their 
  most recent index.

there are 2 cases at the current index r:

1) if the current character str[r] is not present in the window:
    - add it to the window.
    - if the size of the window equals k, we have found a required substring.
        - incement the counter.
        - increment the left pointer (slide the window forward).

2) if the current character str[r] is already present in the window,
   we need to remove its previous occurrence to get rid of the repetition.
   hence, we set the left pointer to the index after the previous occurrence.

time complexity: O(n)
space complexity: O(min(n, 26)) = O(1)
    - since there are 26 characters, the max size of the window is 26.
    - if there were many possible characters (>26), complexity would be O(n).

https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
*/