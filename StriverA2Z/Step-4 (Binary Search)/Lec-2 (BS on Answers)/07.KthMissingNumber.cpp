// Leetcode: 1539. Kth Missing Positive Number (Easy)
// Link: https://leetcode.com/problems/kth-missing-positive-number/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = (low + high) /2;

            int missing = arr[mid] - mid - 1;

            if (missing < k) low = mid +1;
            else high = mid - 1;
        }
        
        return k + high + 1;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector <int> v(n);
        for ( int i =0; i < n ; i++) {
            cin >> v[i];
        }

        Solution sol;
        cout << sol.findKthPositive(v, k) << endl;
    }
    return 0;
}