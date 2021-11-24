/*
 Kosaraju's algorithm is used to find strongly connected
 components (SCC's) in a directed graph.
 It involves performing DFS twice.
 In DFS 1, start from any node which is not visited,
 and after exploring all its children, push it onto the
 stack. Continue until all nodes are pushed onto the stack.
 In DFS 2, first reverse the graph. Keep popping nodes from
 the stack. If the node is not visited, explore all its
 children. When all children of the node are explored,
 add the node to that SCC. Continue until the stack is
 empty (all SCC's are found).
 Time Complexity: O(V + E) (complexity of DFS)
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> components;
vector<int> SCC;
vector<bool> visited(100005, false);
stack<int> s;

void dfs(int node, const vector<vector<int>> &graph, int num)
{
    visited[node] = true;
    for(int i=0;i<graph[node].size();i++)
    {
        if(!visited[graph[node][i]])
            dfs(graph[node][i], graph, num);
    }
    if(num == 0)
        s.push(node);             //dfs1
    else
        SCC.push_back(node);      //dfs2
}

void findSCCs(const vector<vector<int>> &graph)
{
    fill(visited.begin(), visited.end(), false);
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!visited[node])
        {
            SCC.clear();
            dfs(node, graph, 1);
            components.push_back(SCC);
        }
    }
}

int main()
{
    int n, m;
    vector<vector<int>> adjList(100005), adjListRev(100005);
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
        adjListRev[node2].push_back(node1);
    }
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i, adjList, 0);
    findSCCs(adjListRev);
    for(auto &scc : components)
    {
        for(auto node : scc)
            cout << node << " ";
        cout << endl;
    }
    return(0);
}