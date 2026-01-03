// Problem: 802. Find Eventual Safe States (Medium)
// Link: https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    bool dfs(int u, vector<int> &visited, vector<vector<int>>& graph) {
        if (visited[u] != -1) return visited[u];
        visited[u] = 0;

        for (auto &v: graph[u]) {
            if (visited[v] == -1) dfs(v, visited, graph);
            if (visited[v] == 0) return visited[u] = 0;
        }

        return visited[u] = 1;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dfs(i, visited, graph)) ans.push_back(i);
        }

        return ans;
    }
};