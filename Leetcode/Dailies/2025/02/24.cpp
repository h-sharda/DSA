// Problem: 2467. Most Profitable Path in a Tree (Medium)
// Link: https://leetcode.com/problems/most-profitable-path-in-a-tree

class Solution {
public:
    void dfs1(int u, int p, vector<int> &parent, vector<vector<int>> &adj) {
        parent[u] = p;
        for (auto &v: adj[u]) {
            if (v == p) continue;
            dfs1(v, u, parent, adj);
        }
    }

    int dfs2(int u, int p, vector<int> &amount, vector<vector<int>> &adj) {
        int ans = INT_MIN;
        
        for (auto &v: adj[u]) {
            if (v == p) continue;
            ans = max(ans, dfs2(v, u, amount, adj));
        }

        return amount[u] + (ans == INT_MIN ? 0 : ans);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        vector<int> parent(n);

        for (auto &edge: edges) {
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }

        dfs1(0, -1, parent, adj);

        int len = 1;
        for (int node = bob; node != 0; node = parent[node]) len++;
        
        int node = bob;
        for (int i = 0; i < len / 2; i++) amount[node] = 0, node = parent[node];
        if (len % 2) amount[node] /= 2;

        return dfs2(0, -1, amount, adj);
    }
};