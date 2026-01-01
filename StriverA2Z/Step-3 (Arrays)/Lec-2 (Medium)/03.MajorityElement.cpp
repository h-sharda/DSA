// Leetcode: 169. Majority Element (Easy)
// link: https://leetcode.com/problems/majority-element/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), e = nums[0], count = 1;
        for (int i = 1; i < n; i++ ) {
            if (nums[i] == e) count++;
            else {
                if ( count == 0 ) {
                    e = nums[i];
                    count = 1;
                } else count--;
            }
        }
        return e;
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
        cout << ob.majorityElement(nums) << "\n";
    }
    return 0;
}

