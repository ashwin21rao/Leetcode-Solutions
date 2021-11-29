class Solution {
public:
    void dfs(string &node, unordered_map<string, unordered_set<string>> &adjList,
             unordered_set<string> &visited, vector<string> &emails) {
        
        visited.insert(node);
        emails.push_back(node);
        
        for (auto next : adjList[node]) {
            if (visited.find(next) == visited.end())
                dfs(next, adjList, visited, emails);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {        
        unordered_map<string, unordered_set<string>> adjList;
        // email -> name of person
        unordered_map<string, string> names;
        
        // construct graph
        for (auto &account : accounts) {
            string name = account[0];
                
            for (int i=1; i<account.size(); i++) {
                // map email to name
                names[account[i]] = name;
                
                // add new node for email if it doesnt exist
                if (adjList.find(account[i]) == adjList.end())
                    adjList[account[i]] = {};
                
                // add edge between email and previous email
                if (i > 1) {
                    adjList[account[i]].insert(account[i-1]);
                    adjList[account[i-1]].insert(account[i]);
                }
            }
        }
        
        // dfs on constructed graph
        vector<vector<string>> out;
        unordered_set<string> visited;
        
        for (auto &list : adjList) {
            string node = list.first;
            
            if (visited.find(node) == visited.end()) {
                // find all emails in connected component
                vector<string> emails;
                dfs(node, adjList, visited, emails);
                
                // add name and sorted emails to output
                sort(emails.begin(), emails.end());
                out.push_back({names[node]});
                out.back().insert(out.back().end(), emails.begin(), emails.end());
            }
        }
        
        return out;
    }
};

/*
- we consider each email as a node.
- we construct a graph consisting of these emails as nodes.
- we need to divide these emails into disjoint sets or connected components.
- each connected component of this graph represents all emails of one person.

for each account in accounts:
    - we add each email to the graph if not present already.
    - we add an edge between the first email and all other emails in the list,
      hence connecting all of them, since they belong to a single person.

once we have constructed the graph:
    - we perform dfs to get all connected components of the graph. 
    - each component gives us all emails belonging to a single person.
    - we add this to the output, along with the person's name.

n -> number of accounts
k -> is the maximum length of an account: 
time complexity: O(nk)
space complexity: O(nk)

https://leetcode.com/problems/accounts-merge/
*/