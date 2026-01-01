// Leetcode: 1011. Capacity To Ship Packages Within D Days
// link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isValid(vector<int>& weights, int days, int capacity) {
        int n = weights.size(), curr = 0;

        for (int i =0; i < n; i++) {
            if ( curr + weights[i] <= capacity) curr += weights[i];
            else {
                days--;
                curr = weights[i];
            }
            if ( days == 0) return false;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0, ans = -1;
        
        for (int &i: weights ) {
            low = max(low, i);
            high += i;
        }

        while ( low <= high ) {
            int mid = low + (high-low)/2;
            if (isValid(weights, days, mid)) {
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
        
    }
    return 0;
}