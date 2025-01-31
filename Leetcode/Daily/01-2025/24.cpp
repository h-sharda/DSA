// Date: 24/01/2025
// Number: 802. Find Eventual Safe States (Medium)
// link: https://leetcode.com/problems/find-eventual-safe-states/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> incoming(n);
        vector<bool> visited(n, false);
        vector<int> ans;
        queue<int> q;
        
        for (int i =0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                incoming[graph[i][j]].push_back(i);
            }
        }

        
        for (int i =0; i < n ; i++) {
            if ( graph[i].size() == 0) {
                q.push(i);
                visited[i] = true;
            }
        }

        while (!q.empty()) {
            int pos = q.front();
            q.pop();

            for (int &i: incoming[pos]) {
                
                if (visited[i]) continue;
                bool valid = true;
                
                for (int &j: graph[i]) {
                    if (!visited[j]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    q.push(i);
                    visited[i] = true;
                }
            }

        }

        for (int i =0; i < n; i++) if (visited[i]) ans.push_back(i);

        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; 
        vector<vector<int>> graph(n);
        
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                graph[i].push_back(v);
            }
        }

        Solution solution;
        vector<int> result = solution.eventualSafeNodes(graph);

        for (int node : result) cout << node << " ";
        cout << endl;

    }
    
    return 0;
}
