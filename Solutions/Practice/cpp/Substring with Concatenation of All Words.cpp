class Solution {
public:
    // finds substrings using sliding window
    void findSubstring(int start, string s, vector<string> &words, 
                       unordered_map<string, int> &word_freq, vector<int> &ans) {
        
        int n = s.size();
        int num_words = words.size();
        int word_len = words[0].size();
        
        // word -> frequency in current window
        unordered_map<string, int> window_freq;
        
        // loop over string
        int l = start, r = start;
        while (r < n) {
            // extract current word from string
            string word = s.substr(r, word_len);
            window_freq[word]++;
            
            // word used too many times
            if (window_freq[word] > word_freq[word]) {
                // move left pointer after previous occurrence of word
                while (l <= r) {
                    string prev = s.substr(l, word_len);
                    window_freq[prev]--;
                    l += word_len;

                    if (prev == word)
                        break;
                }                
            }
            
            // all words present in window
            else if ((r - l) / word_len + 1 == num_words) {
                ans.push_back(l);
                
                // remove word from beginning of sliding window
                string first = s.substr(l, word_len);
                window_freq[first]--;    
                l += word_len;
            }
            
            r += word_len;
        }
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        // word -> frequency
        unordered_map<string, int> word_freq;
        
        for (string &word : words)
            word_freq[word]++;
        
        // output array
        vector<int> ans;
        
        // fill output
        int word_len = words[0].size();
        for (int i=0; i<word_len; i++)
            findSubstring(i, s, words, word_freq, ans);
        
        return ans;
    }
};

/*
n = length of string s
a = number of words
b = length of each word

we use sliding window (or 2 pointer) approach.
    - the left pointer points to the beginning of the first word in
      the sliding window.
    - the right pointer points to the beginning of the current word
      under consideration.

- if the current size of the sliding is equal to the number of words
  required to be found, we have found a valid substring.
    - append the left pointer (l) to the answer.
    - remove the word at the beginning of the sliding window, 
      that is, slide it forward by one word.

- if after adding the current word, its frequency overshoots:
    - slide the window forward to remove all words upto and including
      the previous occurrence of the word under consideration.
    - this brings its frequnecy back down to the required number.

call the sliding window function b times. this takes care of:
    - overlapping cases. ex: s = "aaaa", words = ["aa", "aa"]
    - trying skipped characters of words in string s which are 
      not found in the words array.

time complexity: O(a + nb)
    - sliding window takes O(n) time
    - we call this function b times

space complexity: O(a + b)
    - the word_freq hashmap takes O(a) space
    - creating substrings takes O(b) space

https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/