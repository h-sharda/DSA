// Date: 01/02/2025
// Number: 3151. Special Array I (Easy)
// link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/


#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool parity = nums[0] & 1;

        for (int &i: nums) {
            if ( (i & 1) && !parity ) return false;
            else if ( !(i & 1) && parity) return false;
            parity = !parity;
        }

        return true;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        Solution sol;
        cout << sol.isArraySpecial(nums) << endl;
    }
    return 0;
}