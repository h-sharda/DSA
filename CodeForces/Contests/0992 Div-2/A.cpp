#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int solve (vector<int> &nums, int k) {
    int n = nums.size();
    if ( n == 1 ) return 1;

    for ( int i = 0; i < n; i++) {
        int count = 0;

        for ( int j = 0; j < n; j++ ) {
            if ( i == j ) continue;
            if ( abs(nums[i]-nums[j]) % k == 0 ) count++;
        }

        if ( count == 0) return i+1;
    }
    return -1;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v[i] = temp;
        }

        int ans = solve(v, k);
        if ( ans == -1) cout << "NO" << endl;
        else cout << "YES\n" << ans << endl;
        
    }
    return 0;
}