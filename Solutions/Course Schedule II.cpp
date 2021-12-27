class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> in_degree(numCourses, 0);
        
        // construct adjacency list
        for (auto &req : prerequisites) {
            adjList[req[1]].push_back(req[0]);
            in_degree[req[0]]++;
        }
        
        // push all nodes with in degree 0 into queue
        // multi source BFS
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (in_degree[i] == 0)
                q.push(i);
        }
        
        vector<int> schedule;
        while (!q.empty()) {
            int node = q.front();
            schedule.push_back(node);
            q.pop();
            
            for (int &next : adjList[node]) {
                in_degree[next]--;
                
                // all parents visited
                if (in_degree[next] == 0)
                    q.push(next);
            }
        }
        
        if (schedule.size() == numCourses)
            return schedule;
        
        // course ordering impossible (loop in graph)
        return {};
    }
};

/*
we create an graph as follows:
    - each course is a node.
    - if course 1 is a prerequisite of course 2, there is a directed edge from 
      course 1 to course 2.

to find a valid course ordering, we find a valid topological ordering of this graph.
we do this using Kahn's algorithm.

V = numCourses
E = size of prerequisites array
time complexity: O(V + E)
space complexity: O(V + E)

https://leetcode.com/problems/course-schedule-ii/
*/