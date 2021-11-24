/*
 ADJACENCY LIST REPRESENTATION OF GRAPH.
 Greedy algo for single source shortest path.
 
 Brief algorithm:
 In each iteration, find the node at shortest distance from the
 source node and mark it as visited. Using relaxation, update
 the distances of all unvisited nodes adjacent to the current node. 
 Repeat until all nodes are visited.

 Start with the source node as the current node and add
 it to the spanSet (or mark it as visited).
 
 Update the distances of all unvisted nodes adjacent to the current
 node using relaxation, that is, check if there is a shorter distance to 
 each adjacent node (v) via the current node (u): 
 d[v] = min(d[v], d[u] + cost(u, v)).
 
 The unvisted node closest to the source becomes the next current
 node and is added to the spanSet.
 This process continues until all nodes have been visited.
 
 Here, the priority queue pq stores all unvisited nodes, 
 in increasing order of their distance from the source node.

 This algorithm does not work if negative edges are present.
 If there are only positive edges, after relaxation, all updated distances
 will be >= the shortest distance calculated for the current node.
 Hence, once a node is visited, there can be no shorter path to it found later
 (so, visited nodes are ignored during relaxation).
 This is not true in the case of negative edges. (algoexpert 19:00)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int,int>>> adjList(100005);
vector<bool> visited(100005, false);
vector<long long int> dist(100005, LONG_LONG_MAX);

void print(int n)
{
    for(int i=1;i<=n;i++)
        cout << dist[i] << " ";
    cout << endl;
}

void dijkstra(int source)
{
    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<>> pq;
    dist[source] = 0;
    pq.push(make_pair(dist[source], source));
    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;
        
        for(int i=0;i<(int)(adjList[node].size());i++)
        {
            int node1 = adjList[node][i].first;
            int weight = adjList[node][i].second;
            if(!visited[node1])
            {
                if(dist[node1] > dist[node] + weight)
                {
                    dist[node1] = dist[node] + weight;
                    pq.push(make_pair(dist[node1], node1));
                }
            }
        }
    }
}

int main()
{
    int n, m, node1, node2, weight, source;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> node1 >> node2 >> weight;
        adjList[node1].emplace_back(node2, weight);
        adjList[node2].emplace_back(node1, weight);
    }
    cin >> source;
    dijkstra(source);
    print(n);
    return(0);
}