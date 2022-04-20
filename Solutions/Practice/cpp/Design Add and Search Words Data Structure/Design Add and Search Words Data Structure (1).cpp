class WordDictionary {
public:
    class Trie {
    public:
        bool endOfWord = false;
        unordered_map<char, Trie*> children;
        
        // searches for word at subtree rooted at node
        bool _search(string &word, Trie *node, int i) {
            if (i == word.size())
                return node->endOfWord;
            
            // if wildcard character, check all children
            if (word[i] == '.') {
                for (auto &[ch, child] : node->children) {
                    if (_search(word, child, i+1))
                        return true;
                }
                return false;
            }
            
            // word not found
            if (node->children.find(word[i]) == node->children.end())
                return false;
                        
            // go to next character
            return _search(word, node->children[word[i]], i+1);
        }
        
        bool search(string &word) {
            return _search(word, this, 0);
        }
        
        // inserts word at node
        void insert(string &word) {
            Trie *node = this;
            
            for (char &ch : word) {
                if (node->children.find(ch) == node->children.end())
                    node->children[ch] = new Trie();
                
                node = node->children[ch];
            }
            
            node->endOfWord = true;
        }
    };
    
    Trie *root = new Trie();
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return root->search(word);
    }
};

/*
we need to search for a word in a given list of words.
we construct a TRIE (prefix tree) for this purpose.

1) addWord: insert a word into the trie
2) search: 
    - search for a word in the trie.
    - whenever we encounter the wildcard character '.', we check all
      possible children of the current node in the trie.
    - hence, we enumerate all possible characters at a wildcard.
    
n = number of words
L = maximum length of word
l = length of current word

time complexity:
    - O(L) to search for a word without wildcards
    - O(nl) to search for a word with wildcards, since in the worst
            case we explore all nodes in the trie.
space complexity: O(nL) to store the trie.

https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/