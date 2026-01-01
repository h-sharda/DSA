// Leetcode: 1283. Find the Smallest Divisor Given a Threshold (Medium)
// link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isValid(vector<int> &nums, int threshold, int divisor) {
        int sum = 0;
        for (int &i: nums) sum += (i + divisor -1)/divisor;
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), ans = -1;

        while ( low <= high ) {
            int mid = low + (high-low)/2;
            if (isValid(nums, threshold, mid)) {
                high = mid-1;
                ans = mid;
            } else low = mid +1;
        }

        return ans;        
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, threshold;
        cin >> n >> threshold;

        vector <int> v(n);
        for ( int i =0; i < n ; i++) {
            cin >> v[i];
        }

        Solution sol;
        cout << sol.smallestDivisor(v, threshold) << endl;
    }
    return 0;
}