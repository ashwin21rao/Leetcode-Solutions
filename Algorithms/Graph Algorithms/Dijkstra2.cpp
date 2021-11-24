/*
 A set is used instead of a priority queue.
*/

#include <iostream>
#include <climits>
#include <vector>
#include <set>

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
    set<pair<long long int,int>> spanSet;
    dist[source] = 0;
    spanSet.insert(make_pair(dist[source], source));
    while(!spanSet.empty())
    {
        int node = spanSet.begin()->second;
        spanSet.erase(spanSet.begin());
        visited[node] = true;
        for(int i=0;i<(int)(adjList[node].size());i++)
        {
            int node1 = adjList[node][i].second;
            int weight = adjList[node][i].first;
            if(!visited[node1])
            {
                spanSet.erase(make_pair(dist[node1], node1));
                dist[node1] = min(dist[node1], dist[node] + weight);
                spanSet.insert(make_pair(dist[node1], node1));
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
        adjList[node1].emplace_back(weight, node2);
        adjList[node2].emplace_back(weight, node1);
    }
    cin >> source;
    dijkstra(source);
    print(n);
    return(0);
}