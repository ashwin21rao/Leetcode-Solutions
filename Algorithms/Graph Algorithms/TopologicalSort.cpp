/*
 Topological sort of a DAG (Directed Acyclic Graph) means
 ordering its vertices in such a way that for every directed
 edge (u -> v), u comes before v in the ordered set of
 vertices.
 This means that the parent node comes before all its
 children in the ordering.
 
 Algorithm: start from any node which is not visited,
 through DFS explore all its children. When all children
 of a node are explored, push that node into the answer set.
 
 NOTE: This algo fails if the directed graph has a cycle.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjList(100005);
vector<bool> visited(100005, false);
vector<int> sorted;

void dfs(int node)
{
    visited[node] = true;
    for(int i=0;i<adjList[node].size();i++)
    {
        if(!visited[adjList[node][i]])
            dfs(adjList[node][i]);
    }
    sorted.push_back(node);
}

void topologicalSort(int n)
{
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
    }
    topologicalSort(n);
    for(auto it=sorted.rbegin(); it!=sorted.rend();it++)
        cout << *it << " ";
    cout << endl;
    return(0);
}