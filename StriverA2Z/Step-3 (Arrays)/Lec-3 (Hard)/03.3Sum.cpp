// Leetcode: 15. 3Sum (Medium)
// link: https://leetcode.com/problems/3sum/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i =0; i < n; i++) {
            while (i > 0 && i < n && nums[i] == nums[i-1]) i++;
            if ( i == n) break;
            
            int target = -nums[i];
            int j = i+1, k = n-1;
            while ( j < k) {
                if (nums[j] + nums[k] == target) {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
                else if (nums[j] + nums[k] < target) j++;
                else k--;
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution s;
        vector<vector<int>> ans = s.threeSum(nums);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}