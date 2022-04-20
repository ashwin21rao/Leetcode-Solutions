class Solution {
public:
    int numKLenSubstrNoRepeats(string str, int k) {
        int n = str.size();
        int count = 0;
        
        // set of characters in sliding window
        unordered_set<char> hash;
        
        int l = 0;
        for (int i=0; i<n; i++) {
            // if character is already seen
            if (hash.find(str[i]) != hash.end()) {
                // remove all characters upto previous occurence
                while (true) {
                    hash.erase(str[l]);
                    
                    if (str[l++] == str[i])
                        break;
                }
            }
            
            // insert current character into hash
            hash.insert(str[i]);
            
            // substring of length k found
            if (i - l + 1 == k) {
                count++;
                
                // slide window forward
                hash.erase(str[l]);
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
- we store a set of characters in the current window.

there are 2 cases at the current index r:

1) if the current character str[r] is not present in the window:
    - add it to the window.
    - if the size of the window equals k, we have found a required substring.
        - incement the counter.
        - delete the leftmost character of the window str[l] and increment 
          the left pointer (slide the window forward).

2) if the current character str[r] is already present in the window,
   we need to remove its previous occurrence to get rid of the repetition.
    - increment the left pointer and remove all characters from the window
      until we reach the previous occurrence of str[r].
    - add the current character to the window.

time complexity: O(n)
space complexity: O(min(k, 26)) = O(1)
    - since there are 26 characters, the max size of the window is 26.
    - if there were many possible characters (>26), complexity would be O(k).

https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
*/