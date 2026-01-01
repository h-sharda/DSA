// Leetcode: 1. Two Sum (Easy)
// link: https://leetcode.com/problems/two-sum/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> umap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int cmp = target - nums[i];
            if (umap.contains(cmp)) return {i, umap[cmp]};
            umap[nums[i]] = i;
        }

        return {-1, -1};
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        Solution ob;
        vector<int> ans = ob.twoSum(nums, target);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}