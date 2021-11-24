/*
 EDGE LIST REPRESENTATION OF GRAPH.
 DP algo for single source shortest path in a
 directed graph.
 Used to detect the presence of a negative edge cycle,
 reachable from the given source vertex.
 We create an edge list, and perform relaxation for all
 (directed) edges in the graph.
 If the graph is undirected, we consider each undirected
 edge as 2 directed edges, and push both into the edge list.
 In this case, the total number of edges is considered to
 be (2*E).
 The relaxation of all edges is carried out (V-1) times.
 In the i'th iteration, the shortest path of i edges
 is found. Since the maximum number of edges in a simple
 path between 2 vertices is (V-1), the process is repeated
 (V-1) times.
 To check if a negative edge cycle (reachable from the
 source node) is present, we relax all edges once more. If
 the shortest path of any vertex changes, then that vertex
 is a part of, or connected to, a negative edge cycle in
 the graph. At least 1 such vertex will be found, if a
 negative edge cycle is present.
 NOTE: This algorithm does not identify all vertices in the
 negative edge cycle.
 Time complexity: O(VE) (V - vertices, E - edges)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edgeList;
vector<int> dist(100005, INT_MAX);

void print(int n)
{
    for(int i=1;i<=n;i++)
        cout << dist[i] << " ";
    cout << endl;
}

bool bellmanFord(int source, int n)
{
    dist[source] = 0;
    for(int i=0;i<n-1;i++)
    {
        for(auto &edge : edgeList)
        {
            int src = edge[0], dest = edge[1], weight = edge[2];
            if(dist[src] != INT_MAX && dist[dest] > dist[src] + weight)
                dist[dest] = dist[src] + weight;
        }
    }
    for(auto &edge : edgeList)
    {
        int src = edge[0], dest = edge[1], weight = edge[2];
        if(dist[src] != INT_MAX && dist[dest] > dist[src] + weight)
            return(true);
    }
    return(false);
}

int main()
{
    int n, m, node1, node2, weight, source;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> node1 >> node2 >> weight;
        edgeList.push_back({node1, node2, weight});
        //if graph is undirected
        //edgeList.push_back({node2, node1, weight});
    }
    cin >> source;
    if(!bellmanFord(source, n))
        print(n);
    else
        cout << "Negative edge cycle reachable from source" << endl;
    return(0);
}