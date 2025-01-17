// Leetcode: 1482. Minimum Number of Days to Make m Bouquets (Medium)
// link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:

    bool isValid (vector<int> &bloomDay, int bouquets, int k, int days) {
        int n = bloomDay.size();

        for (int i =0; i < n && bouquets > 0; ) {
            int j = i;
            while (j-i < k && j < n && bloomDay[j] <= days) j++;

            if ( j-i == k ) bouquets--;
            
            i = i == j ? i + 1 : j;
        }

        return bouquets == 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0, high = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;

        while ( low <= high ) {
            int mid = low + (high-low)/2;
            if (isValid(bloomDay, m, k, mid)) {
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
        int n, m, k;
        cin >> n >> m >> k;

        vector <int> v(n);
        for ( int i =0; i < n ; i++) {
            cin >> v[i];
        }

        Solution sol;
        cout << sol.minDays(v, m, k) << endl;
    }
    return 0;
}