class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;
        
        int i1 = 0;  // index into string
        int i2 = 0;  // index into pattern
        
        int n1 = s.size();
        int n2 = pattern.size();
        
        while (i1 < n1 && i2 < n2) {
            // extract word
            int j = i1;
            string word = "";
            while (j < n1 && s[j] != ' ') {
                word += s[j];
                j++;
            }
            i1 = j + 1;
            
            // extract character
            char ch = pattern[i2];
            i2++;
            
            // check mapping
            if (char_to_word.find(ch) != char_to_word.end() && 
                char_to_word[ch] != word) {
                return false;
            }
            if (word_to_char.find(word) != word_to_char.end() &&
                word_to_char[word] != ch) {
                return false;
            }
            
            // add mapping
            char_to_word[ch] = word;
            word_to_char[word] = ch;            
        }
        
        return (i1 == n1 + 1 && i2 == n2);
    }
};

/*
we create 2 hash maps:
    - character in pattern -> word in string
    - word in string -> character in pattern

- a character should map to a single word
- a word should map to a single character
- the number of words and characters should be equal.

time complexity: O(n) where n is the length of the string
space complexity: O(26) = O(1)
*/