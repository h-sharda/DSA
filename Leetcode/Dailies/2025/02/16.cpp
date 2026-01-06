class Solution {
public:
    bool r(int pos, int n, vector<int> &curr, vector<bool> &vis) {
        if (pos == 2 * n - 1) {
            for (int i = 1; i <= n; i++) if (!vis[i]) return false;
            return true;
        }

        if (curr[pos]) return r(pos + 1, n, curr, vis);

        for (int i = n; i > 0; i--) {
            if (vis[i]) continue;

            vis[i] = true;
            
            if (i == 1) {
                curr[pos] = 1;
                if (r(pos + 1, n, curr, vis)) return true;
                curr[pos] = 0;
            } else if (pos + i < 2 * n - 1 && curr[pos + i] == 0) {
                curr[pos] = curr[pos + i] = i;
                if (r(pos + 1, n, curr, vis)) return true;
                curr[pos] = curr[pos + i] = 0;
            }

            vis[i] = false;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> curr(2 * n - 1);
        vector<bool> vis(n + 1);
        if (r(0, n, curr, vis)) return curr;
        return {};
    }
};