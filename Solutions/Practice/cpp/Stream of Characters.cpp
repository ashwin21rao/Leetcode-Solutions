class StreamChecker {
public:
    class TrieNode {
    public:
        bool endOfWord = false;
        unordered_map<char, TrieNode*> children;
        
        // insert words in reverse at this node
        void insert(string &word) {
            TrieNode *node = this;
            
            int n = word.size();
            for (int i=n-1; i>=0; i--) {
                char ch = word[i];
                if (node->children.find(ch) == node->children.end())
                    node->children[ch] = new TrieNode();
                
                node = node->children[ch];
            }
            
            node->endOfWord = true;
        }
        
        // search for a suffix of word in reverse starting at this node
        bool search(string &word) {
            TrieNode *node = this;
            
            int n = word.size();
            for (int i=n-1; i>=0; i--) {
                char ch = word[i];
                
                // no suffix found in trie
                if (node->children.find(ch) == node->children.end())
                    return false;
                
                // suffix is a word in trie
                if (node->children[ch]->endOfWord)
                    return true;
                
                node = node->children[ch];
            }
            
            // entire word is present in trie
            return node->endOfWord;
        }
    };
    
    TrieNode *root = new TrieNode();
    string stream = "";
    
    StreamChecker(vector<string>& words) {
        // insert all words into trie in reverse
        for (auto &word : words)
            root->insert(word);
    }
    
    bool query(char letter) {
        stream += letter;
        
        // search for stream in reverse
        return root->search(stream);
    }
};

/*
- we need to search for all suffixes of a word in a list of words.
- this is the same as searching for all prefixes of the reversed word 
  in the list of reversed words.
- this is a standard use-case of a trie.

- insert all words into a trie in reverse order.
- we consider the reversed character stream.
- we check if any prefix of the reversed character stream is present in the trie.

time complexity: O(min(L, n)) per query, where
    L is the length of the longest word in the trie
    n is the length of the stream of characters

time complexity: O(mL) for trie construction (preprocessing)
space complexity: O(mL) where
    L is the length of the longest word in the trie
    m is the length of the words array

https://leetcode.com/problems/stream-of-characters/
*/