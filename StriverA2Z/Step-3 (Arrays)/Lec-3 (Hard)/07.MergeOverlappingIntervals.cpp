// Leetcode: 56. Merge Intervals (Medium)
// Link: https://leetcode.com/problems/merge-intervals/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int start = intervals[0][0], end = intervals[0][1];
        for (const auto &it: intervals) {
            if (it[0] <= end) end = max(end, it[1]);
            else {
                ans.push_back({start, end});
                start = it[0], end = it[1];
            }
        }
        ans.push_back({start, end});

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
        vector<vector<int>> intervals(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution s;
        vector<vector<int>> result = s.merge(intervals);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i][0] << " " << result[i][1] << endl;
        }
    }
    return 0;
}