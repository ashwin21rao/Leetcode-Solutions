/*
A disjoint set union (DSU) data structure is used when there
is a set of elements divided into disjoint subsets.

The elements can be thought of as nodes.
The subsets can be thought of as trees containing nodes.

The following operations are possible on a DSU:
	- findRoot(node): 
		- finds which set an element belongs to.
		- returns the root of the tree representing that subset.

	- findUnion(node1, node2): 
		- combine the 2 sets containing node1 and node2 into a single set.
		- attach the root of one tree to the root of the other.

The following data structures are needed:
	- parent[]: for each node, stores the parent node.
	- rank[]: for each node, stores the rank (depth) of the tree 
			  rooted at that node (without path compression).

Path compression: optimization in the findRoot() function.
	- For each ancestor along the path from the given node to the root,
	  we set the parent of the node to be equal to the root.
	- This compresses the path from each ancestor to the root.

Union by rank: optimization in the findUnion() function.
	- When finding the union of two trees, we attach the root of the 
	  tree with lower depth to the root of the tree with greater depth.
  	- This results in all created trees being balanced, hence having
  	  a maximum height of O(log n).

With path compression and union by rank optimization,
time complexity of findRoot() and findUnion() are both O(1).
*/


#include <vector>

// findRoot() with path compression
int findRoot(int node, vector<int> &parent) {
	if (node == parent[node])
		return node;
	return parent[node] = findRoot(parent[node], parent);
}

// findUnion() with union by rank
bool findUnion(int node1, int node2, vector<int> &parent, vector<int> &rank) {
	int root1 = findRoot(node1);
	int root2 = findRoot(node2);

	// nodes are in the same subset
	if (root1 == root2)
		return false;

	if (rank[root1] < rank[root2])
		parent[root1] = root2;
	else if (rank[root2] < rank[root1])
		parent[root2] = root1;
	else {
		parent[root2] = root1;
		rank[root1]++;
	}

	return true;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> parent(n);
	vector<int> rank(n);

	// initially, each node is its own subset
	// hence parent[node] = node and rank[node] = 1
	for (int i=0; i<n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}

	return 0;
}