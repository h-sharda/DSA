// Problem: 1462. Course Schedule IV (Medium)
// Link: https://leetcode.com/problems/course-schedule-iv

class Solution {
public:
    void fillGraph(unordered_map<int, unordered_set<int>> &graph, vector<bool> &visited, vector<vector<int>> &adj, int course) {
        if (adj[course].size() == 0) visited[course] = true;
        if (visited[course]) return;

        for (int &pre: adj[course]) {
            if (!visited[pre]) fillGraph(graph, visited, adj, pre);
            graph[course].insert(graph[pre].begin(), graph[pre].end());
            graph[course].insert(pre);
        }

        visited[course] = true;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses), ans;
        unordered_map<int, unordered_set<int>> graph;
        
        for (auto edge : prerequisites) adj[edge[1]].push_back(edge[0]);

        for (int i = 0; i < numCourses; i++) fillGraph(graph, visited, adj, i);
        
        for (auto &it: queries) ans.push_back(graph[it[1]].contains(it[0]));
        
        return ans;

    }
};