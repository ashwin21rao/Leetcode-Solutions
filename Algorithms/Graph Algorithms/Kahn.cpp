/*
 Kahn's Algorithm is used for topological sorting of a
 Directed Acyclic Graph (DAG).
 
 Logic : When a node has no incoming edges (in degree = 0),
 it can be added to the answer array, as its parents have
 already been explored.
 
 Kahn's Algorithm does topological sorting by multi-source
 BFS. Each source is a node with no incoming edges. For each
 node with in degree = 0, we add it to the answer array and
 remove the edges between the node and its children. If
 any of its children now have no incoming edges, we add it
 to the queue as a source node.
 
 NOTE: Kahn's algorithm fails to include nodes which are part
 of a loop, as these nodes can never have in degree = 0.
 Time complexity: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjList(100005);
vector<int> in_degree(100005, 0), sorted;

void kahn(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in_degree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        sorted.push_back(node);
        for(int i=0;i<(int)adjList[node].size();i++)
        {
            in_degree[adjList[node][i]]--;
            if(in_degree[adjList[node][i]] == 0)
                q.push(adjList[node][i]);
        }
    }
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
        in_degree[node2]++;
    }
    kahn(n);
    for(int i=0;i<n;i++)
        cout << sorted[i] << " ";
    cout << endl;
    return(0);
}