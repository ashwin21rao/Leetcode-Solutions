class Solution {
public:
    // BFS to find shortest path between beginWord and endWord
    int bfs(int src, int dest, vector<vector<int>> &adjList) {
        vector<int> visited(adjList.size(), false);
        queue<int> q;
        
        // insert source
        q.push(src);
        visited[src] = true;
        
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            
            for (int i=0; i<size; i++) {
                int node = q.front();
                q.pop();
                
                // end word reached
                if (node == dest)
                    return level;
                
                for (int &next : adjList[node]) {
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            level++;
        }
        
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        
        // source and dest nodes for BFS
        int src = n-1;  // index of beginWord
        int dest = -1;  // index of endWord
        
        // word- > index
        unordered_map<string, int> words;
        for (int i=0; i<n; i++) {
            words[wordList[i]] = i;
            
            if (wordList[i] == endWord)
                dest = i;
        }
        
        // construct adjacency list
        vector<vector<int>> adjList(n);
        
        for (string &word : wordList) {
            int node = words[word];
            
            // replace each character with a-z
            for (char &ch : word) {
                char original = ch;
                
                for (char c='a'; c<='z'; c++) {
                    if (c == original) continue;
                    ch = c;
                    
                    // add edge
                    if (words.find(word) != words.end())
                        adjList[node].push_back(words[word]);
                }
                ch = original;
            }
        }
        
        return bfs(src, dest, adjList);
    }
};

/*
we construct a graph of words in wordList as follows:
    - each word in wordList is a node.
    - beginWord is the source.
    - endWord is the destination.
    - there is an edge between word1 and word2 if they differ by a single letter.
    - the shortest distance between source and destination is found using BFS.
    - this is the minimum length transformation sequence.

constructing adjacency list:
    - for each word in wordList, generate all words which differ from it
      by 1 character. if the word exists in the graph, add an edge.
    - there are 26 possible words for each letter.
    - hence the maximum number of edges connected to a node is O(26L) = O(L).
    - time complexity: O(n * 26L) = O(nL)

BFS time complexity optimization:
    - to prevent comparing strings in BFS, each node in the graph is the 
      index of the corresponding string in wordList.
    - this improves BFS time complexity from O(n * L^2) to O(nL).
    
number of vertices = V = O(n)
number of edges = E = O(n * 26L) = O(nL)

time complexity: O(V + E) = O(26nL) = O(nL)
space complexity: O(V + E) = O(26nL) = O(nL)

https://leetcode.com/problems/word-ladder/
*/