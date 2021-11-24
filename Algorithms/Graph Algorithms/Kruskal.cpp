/*
 EDGE LIST REPRESENTATION OF GRAPH.
 Greedy algo to find MST.
 Sort all the edges in the edge list in increasing
 order of weights.
 Add the minimum weight edges one by one into the
 spanning tree.
 If adding the edge forms a cycle (detected by disjoint
 set union), skip that edge and add the next smallest edge.
 Continue adding edges until (n-1) edges have been added
 (as MST has n-1 edges).
 Time complexity: O(n) (DSU is constant complexity)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> edgeList;
vector<int> parent;

int findRoot(int node)
{
    if(parent[node] == node)
        return(node);
    return(parent[node] = findRoot(parent[node]));
}

bool findUnion(int node1, int node2)
{
    int root1 = findRoot(node1);
    int root2 = findRoot(node2);
    if(root1 != root2)
    {
        parent[root2] = root1;
        return(true);
    }
    return(false);
}

long long int findMST(int n, int m)
{
    int count = 0;
    vector<int> edge;
    long long int sum = 0;
    for(int i=0;i<m;i++)
    {
        edge = edgeList[i];
        if(findUnion(edge[1], edge[2]))
            sum += edge[0], count++;
        if(count == n-1)
            break;
    }
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
        edgeList.push_back({weight, node1, node2});
    }
    parent.push_back(-1);
    for(int i=1;i<=n;i++)
        parent.push_back(i);
    sort(edgeList.begin(), edgeList.end());
    ans = findMST(n, m);
    cout << ans << endl;
    return(0);
}