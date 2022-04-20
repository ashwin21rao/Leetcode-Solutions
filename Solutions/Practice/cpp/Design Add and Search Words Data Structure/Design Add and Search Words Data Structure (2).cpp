class WordDictionary {
public:
    // length -> words with that length
    unordered_map<int, vector<string>> words;
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    bool search(string word) {
        int n = word.size();
        
        // iterate over all words with same length
        for (string &str : words[n]) {
            bool found = true;
            
            // check match
            for (int i=0; i<n; i++) {
                // wildcard can match any character
                if (word[i] == '.')
                    continue;
                if (str[i] != word[i]) {
                    found = false;
                    break;
                }
            }
            
            // entire word matched
            if (found)
                return true;
        }
        
        // word not found
        return false;
    }
};

/*
we maintain a hashmap which maps lengths to all words with that length.

1) addWord: add word to hashmap
2) search:
    - iterate over all words in hashmap with same length as the word
      to be searched.
    - compare the word to be searched with each of these words.
      the wildcaard can map to any character.

disadvantage over trie:
    - trie has better space complexity since prefixes are stored only 
      once.
    - as the size of the hashmap increases, hash collisions degrade time
      complexity.
      
n = number of words
L = maximum lenghth of word

time complexity: O(nL) since we iterate over all words
space complexity: O(nL) to store all words

https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/