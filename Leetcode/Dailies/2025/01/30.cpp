// Problem: 2493. Divide Nodes Into the Maximum Number of Groups (Hard)
// Link: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups

class Solution {
public:
    bool check(int u, int color, vector<vector<int>> &adj, vector<int> &colors, vector<int> &ids, int id) {
        colors[u] = color;
        ids[u] = id;

        for (int v: adj[u]) {
            if (colors[v] == color) return false;
            int target = color == 1 ? 2 : 1;
            if (colors[v] == target) continue;
            if (!check(v, target, adj, colors, ids, id)) return false;
        }

        return true;
    }

    int dist(int node, vector<vector<int>> &adj) {
        vector<bool> visited(adj.size());
        visited[node] = true;

        queue<int> q;
        q.push(node);

        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int u = q.front();
                q.pop();

                for (int v: adj[u]) {
                    if (visited[v]) continue;
                    visited[v] = true;
                    q.push(v);
                }
            }

            ans++;
        }

        return ans;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for (auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> colors(n+1), ids(n+1);
        int id = 1;
        for (int i = 1; i <= n; i++) {
            if (colors[i] != 0) continue;
            if (!check(i, 1, adj, colors, ids, id)) return -1;
            id++;
        }

        int ans = 0;
        
        for (int i = 1; i < id; i++) {
            int maxx = 0;
            for (int j = 1; j <= n; j++) if (ids[j] == i) maxx = max(maxx, dist(j, adj));
            ans += maxx;
        }

        return ans;
    }
};