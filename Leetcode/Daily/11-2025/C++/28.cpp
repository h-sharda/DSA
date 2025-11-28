// Problem: 2872. Maximum Number of K-Divisible Components (Hard)
// Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components

class Solution {
public:
    int dfs(int curr, int prev, vector<vector<int>> &adj, vector<int> &values, int k, int &ans) {
        int sum = 0;

        for ( auto &i: adj[curr]) {
            if (i == prev) continue;
            sum += dfs(i, curr, adj, values, k, ans);
            sum %= k;
        }

        sum += values[curr];
        sum %= k;

        if ( sum == 0 ) ans++;

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> adj(n);
        for ( int i =0; i < n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        dfs(0, -1, adj, values, k, ans);
        return ans;
    }
};