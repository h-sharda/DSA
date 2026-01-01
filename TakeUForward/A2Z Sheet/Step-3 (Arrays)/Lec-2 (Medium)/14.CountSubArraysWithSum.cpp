// Leetcode: 560. Subarray Sum Equals K (Medium)
// https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum  =0;
        
        unordered_map <int, int> umap;

        for (int i =0; i < n; i++) {
            sum += nums[i];
            if (umap.contains( sum - k) ) ans += umap[sum-k];
            if (sum == k) ans++;
            umap[sum]++;
        }

        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        cout << sol.subarraySum(nums, k) << endl;      
    }
    return 0;
}