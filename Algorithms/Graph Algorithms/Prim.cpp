/*
 ADJACENCY LIST REPRESENTATION OF GRAPH.
 Greedy algo to find MST.
 
 Brief algorithm:
 In each iteration, find the node at shortest distance from any node 
 in the spanSet and add it to the spanSet. Update the distances of all 
 unvisited nodes adjacent to the current node, if required.
 Repeat until all nodes are in the spanSet. 

 Start from any node, add it to the spanSet.
 
 Find the node not present in the spanSet, closest to any
 node in the spanSet.
 
 Add this node to the spanSet.
 
 Continue this process until all nodes are in the spanSet.
 
 This algo is very similar to dijkstra. Here, instead of
 storing the distances of the nodes from the source, each node
 has a key which stores its distance from the nearest node already
 preset in the spanSet.
*/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int,int>>> adjList(100005);
vector<bool> visited(100005, false);
vector<long long int> key(100005, LONG_LONG_MAX);

long long int findMST(int n)
{
    long long int sum = 0;
    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<>> pq;
    int start = 1;
    key[start] = 0;
    pq.push(make_pair(key[start], start));
    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        visited[node] = true;
        for(int i=0;i<(int)(adjList[node].size());i++)
        {
            int node1 = adjList[node][i].first;
            int weight = adjList[node][i].second;
            if(!visited[node1])
            {
                if(key[node1] > weight)
                {
                    key[node1] = weight;
                    pq.push(make_pair(key[node1], node1));
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        sum += key[i];
    return(sum);
}

int main()
{
    int n, m, node1, node2, weight;
    long long int ans;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> node1 >> node2 >> weight;
        adjList[node1].emplace_back(node2, weight);
        adjList[node2].emplace_back(node1, weight);
    }
    ans = findMST(n);
    cout << ans << endl;
    return(0);
}