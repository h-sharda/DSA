// Leetcode: 128. Longest Consecutive Sequence (Medium)
// link: https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set <int> uset (nums.begin(), nums.end());

        int ans = 0;
        for (int i: uset){
            if ( !uset.contains(i-1)){
                int temp = i, len = 0;
                while (uset.contains(temp++))  len++;
                ans = max(ans, len);
            }
        }

        return ans ;

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
        cout << ob.longestConsecutive(nums) << "\n";
    }
    return 0;
}