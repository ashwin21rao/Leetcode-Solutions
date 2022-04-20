class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        
        // position -> routes it is present in
        unordered_map<int, unordered_set<int>> routes_map;
        
        int n = routes.size();
        for (int i=0; i<n; i++) {
            for (int &position : routes[i])
                routes_map[position].insert(i);
        }
        
        // nulti-source bfs
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        
        // add all sources to queue
        for (auto &route : routes_map[source]) {
            q.push({route, 1});
            visited[route] = true;            
        }
        
        while (!q.empty()) {            
            auto [node, level] = q.front();
            q.pop();
            
            // check if destination is reached
            if (routes_map[target].find(node) != routes_map[target].end())
                return level;
            
            // traverse neighbouring nodes (implicit adjacency list)
            for (int &position : routes[node]) {
                for (auto &next : routes_map[position]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push({next, level + 1});
                    }
                }
            }
        }
        
        // no way to reach target
        return -1;
    }
};

/*
we need to find the minimum number of bus routes to go from the source to target.

- we consider each bus route as a node.
- if 2 bus routes are connected, there is an undirected edge between them.
- since multiple routes can contain the source and target, there can be multiple
  source nodes and multiple target nodes.
- we use BFS to find the minimum distance between a source and target node in this 
  uweighted graph.
  
to find which route is connected to which other routes, we construct an unordered map.
    - this maps each location to all routes it is present in.
    - a route is connected to all other routes which share a location with it.
    - we can use this map to find all neighbours of a node, and do not need to explicitly
      construct an adjacency list.

V = number of routes = n
E = number of edges = O(n^2)
b = max length of bus route 

without constructing the adjacency list:
    - BFS takes O(nb) time since we loop over all possible connections (not just edges)
    - time complexity: O(nb + nb) = O(nb) 
    - space complexity: O(nb) for the map

constructing the adjacency list:
    - BFS takes O(n^2) time since we loop over only edges
    - time complexity: O(nb + n^2) since we loop over only edges
    - space complexity: O(nb + n^2) for the map and adjacency list

https://leetcode.com/problems/bus-routes/
*/