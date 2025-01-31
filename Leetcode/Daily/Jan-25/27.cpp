// Date: 27/01/2025
// Number: 1462. Course Schedule IV (Medium)
// link: https://leetcode.com/problems/course-schedule-iv/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

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

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int numCourses;
        cin >> numCourses;
        vector<vector<int>> prerequisites, queries;
        int n, m;
        cin >> n;
        for (int i = 0; i < n; i++) {
            vector<int> temp(2);
            cin >> temp[0] >> temp[1];
            prerequisites.push_back(temp);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            vector<int> temp(2);
            cin >> temp[0] >> temp[1];
            queries.push_back(temp);
        }
        Solution sol;
        vector<bool> ans = sol.checkIfPrerequisite(numCourses, prerequisites, queries);
        for (bool it: ans) cout << it << " ";
        cout << endl;
    }
    
    return 0;
}
