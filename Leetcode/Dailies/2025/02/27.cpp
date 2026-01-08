class Solution {
public:
    int r(int a, int b, vector<int> &arr, vector<vector<int>> &memo, unordered_map<int, int> &umap) {
        if (memo[a][b]) return memo[a][b];
        if (!umap.contains(arr[a] + arr[b])) return memo[a][b] = 2;
        return memo[a][b] = r(b, umap[arr[a] + arr[b]], arr , memo, umap) + 1;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0, n = arr.size();
        vector<vector<int>> memo(n, vector<int>(n));
        unordered_map<int, int> umap;
        for(int i = 0; i < n; i++) umap[arr[i]] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, r(i, j, arr, memo, umap));
            }
        }

        return ans > 2 ? ans : 0;
    }
};