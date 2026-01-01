// Leetcode: 2149. Rearrange Array Elements by Sign (Medium)
// link: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pos = 0, neg = 0;
        bool isPos = true;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (isPos) {
                while (nums[pos] < 0) pos++;
                ans[i] = nums[pos++];
            } else {
                while (nums[neg] > 0) neg++;
                ans[i] = nums[neg++];
            }
            isPos = !isPos;
        }

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
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        Solution ob;
        vector<int> ans = ob.rearrangeArray(nums);
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}