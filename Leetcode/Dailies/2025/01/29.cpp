// Date: 29/01/2025
// Number: 684. Redundant Connection (Medium)
// link: https://leetcode.com/problems/redundant-connection/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int n;

    bool hasCycle(vector<vector<int>> &v, vector<int> &edge) {
        int target = edge[0], start = edge[1];
        
        vector<bool> visited(n + 1);
        visited[start] = true;

        queue<int> q;
        for (int &i: v[start]) {
            if (i == target) continue;
            q.push(i);
            visited[i] = true;
        }

        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            if (pos == target) return true;

            for (int &i: v[pos]) {
                if (visited[i]) continue;
                q.push(i);
                visited[i] = true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<vector<int>> v(n + 1);

        for (const auto &it: edges) {
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }

        for (int i = n-1; i >= 0; i--) if (hasCycle(v, edges[i])) return edges[i];

        return {-1, -1};
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> v(n, vector<int>(2));
        for (int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1];
        
        Solution ob;
        vector<int> ans = ob.findRedundantConnection(v);
        
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    }
    
    return 0;
}
