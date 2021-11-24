/*
 ADJACENCY MATRIX REPRESENTATION OF GRAPH.
 DP algo to find all source shortest path.
 Floyd warshall can also be used to detect the presence of a
 negative edge cycle in a graph.
 After the algorithm is completed, we check if the distance of
 any vertex from itself is negative (dist[i][i] < 0). If so, a
 negative edge cycle is present, accessible from that vertex.
*/

#include <iostream>
#include <vector>

using namespace std;

// adjMatrix[i][j] stores weight of edge between node i and node j
vector<vector<int>> dist(1000, vector<int>(1000, INT_MAX));

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}

void floydWarshall(int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
}

int main()
{
    int n, m, node1, node2, weight;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> node1 >> node2 >> weight;
        dist[node1-1][node2-1] = dist[node2-1][node1-1] = weight;  //undirected graph
    }
    for(int i=0;i<n;i++)
        dist[i][i] = 0;
    floydWarshall(n);
    print(n);
    return(0);
}