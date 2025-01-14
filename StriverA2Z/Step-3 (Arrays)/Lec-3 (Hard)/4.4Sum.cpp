// Leetcode: 18. 4Sum (Medium)
// link: https://leetcode.com/problems/4sum/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int sum) {
        int n = nums.size();
        if ( n < 4 ) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int a =0; a < n-3; a++ ) {
            while (a != 0 && a < n-3 && nums[a] == nums[a-1]) a++;
            if ( a >= n-3) break;

            for (int i = a + 1; i < n-2; i++) {
                while (i != a + 1 && i < n-2 && nums[i] == nums[i-1]) i++;
                if ( i >= n-2) break;
                
                long long target = 0LL + sum - nums[a] - nums[i];
                if ( target > INT_MAX || target < INT_MIN) continue;
                
                int j = i+1, k = n-1;
                while ( j < k) {
                    if (nums[j] + nums[k] == target) {
                        ans.push_back({nums[a], nums[i], nums[j++], nums[k--]});
                        while (j < k && nums[j] == nums[j-1]) j++;
                        while (j < k && nums[k] == nums[k+1]) k--;
                    }
                    else if (nums[j] + nums[k] < target) j++;
                    else k--;
                }
            }
        }

        return ans;
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
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution s;
        vector<vector<int>> ans = s.fourSum(nums, target);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}