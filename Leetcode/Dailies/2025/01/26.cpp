// Problem: 2127. Maximum Employees to Be Invited to a Meeting (Hard)
// Link: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting

class Solution {
public:
    int x = 0;

    // Creates connected components
    void dfs1(int u, vector<int> &fav, vector<bool> &visited, vector<vector<int>> &rev, vector<vector<int>> &conn) {
        conn.back().push_back(u);
        if (!visited[fav[u]]) {
            visited[fav[u]] = true;
            dfs1(fav[u], fav, visited, rev, conn);
        }
        for (int &v: rev[u]) if (!visited[v]) {
            visited[v] = true;
            dfs1(v, fav, visited, rev, conn);
        }
    }

    // Evaluates maxx in a connected component
    int eval(vector<int> &comp, vector<int> &fav, vector<vector<int>> &rev) {
        unordered_map<int, int> level;
        level[comp[0]] = 0;

        return dfs2(comp[0], -1, fav, rev, level);
    }

    // Finds cycle in the connected component
    int dfs2(int curr, int prev, vector<int> &fav, vector<vector<int>> &rev, unordered_map<int, int> &level) {
        int next = fav[curr];
        
        if (prev == next) {
            x += dfs3(curr, prev, rev) + dfs3(prev, curr, rev);
            return 0;
        }

        if (level.contains(next)) return level[curr] - level[next] + 1;
        
        level[next] = level[curr] + 1;
        return dfs2(next, curr, fav, rev, level);
    }

    // This section of connected component is just a tree
    int dfs3(int curr, int prev, vector<vector<int>> &rev) {
        int ans = 0;
        
        for (int &next: rev[curr]) {
            if (next == prev) continue;
            ans = max(ans, dfs3(next, curr, rev));
        }

        return ans + 1;
    }

    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();

        vector<vector<int>> rev(n), conn;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) rev[fav[i]].push_back(i);
        for (int i = 0; i < n; i++) if (!visited[i]) {
            conn.push_back({});
            dfs1(i, fav, visited, rev, conn);
        }

        int ans = 0;
        for (auto &comp: conn) ans = max(ans, eval(comp, fav, rev));

        return max(ans, x);
    }
};