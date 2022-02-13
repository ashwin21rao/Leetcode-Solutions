class Solution {
public:
    // find shortest distance between source and destination using BFS
    int bfs(string src, string dest, unordered_map<string, vector<string>> &adjList) {
        unordered_set<string> visited;
        queue<string> q;
        
        // insert source
        q.push(src);
        visited.insert(src);
        
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            
            for (int i=0; i<size; i++) {
                string node = q.front();
                q.pop();
                
                // destination reached
                if (node == dest)
                    return level;
                
                // loop over all intermediate nodes adjacent to node
                int len = node.size();
                string inter_node = node;
                
                for (int j=0; j<len; j++) {
                    inter_node[j] = '*';
                    
                    // loop over all nodes adjacent to intermediate nodes
                    for (string &next : adjList[inter_node]) {
                        if (visited.find(next) == visited.end()) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                    
                    inter_node[j] = node[j];
                }
            }
            level++;
        }
        
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        // construct adjacency list of intermediate nodes
        unordered_map<string, vector<string>> adjList;
        
        for (string &word : wordList) {
            int size = word.size();
            string new_word = word;
            
            for (int i=0; i<size; i++) {
                new_word[i] = '*';
                
                // add edge
                adjList[new_word].push_back(word);
                
                new_word[i] = word[i];
            }
        }
        
        return bfs(beginWord, endWord, adjList);
    }
};

/*
this solution does not have the additional O(26) in its time complexity.
hence it generalizes to an alphabet with larger number of characters.

each word has a set of intermediate words.
    - these are words which differ from the word by one character
    - they are represented using a '*' in the position which can
      have any character.
    - a word of length L has L intermediate words (a character can differ
      in any position).
    - example: dog -> *og, d*g, do* are intermediate words
    
we construct a graph as follows:
    - each word in wordList is a node.
    - intermediate words of all words are nodes.
    - edges exist between nodes and their intermediate nodes.
    - we perform BFS on this graph to find the shortest distance between source and
      destination.
    - this is the required minimum transformation sequence length.

optimized implementation (without storing all nodes in adjacency list):
    - we store the intermediate nodes in the adjacency list.
    - in BFS, the queue contains only nodes (not intermiedate nodes).
    - for the current node, loop over all its intermediate nodes.
    - loop over all nodes of each intermediate node and add it to the queue
      if not visited. hence, we go to the next word in wordList
    - in this way, we perform BFS only on nodes and skip intermidate nodes.
    - the number of levels is the required answer.

n = number of words
L = length of longest word

time complexity: O(n * L^2)
space complexity: O(n * L^2)
the extra O(L) is due to storing strings as nodes in the adjacency list.

https://leetcode.com/problems/word-ladder/
*/