#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        long long n, x, y, sum = 0, ans = 0;
        cin >> n >> x >> y;
        vector<long long> v(n, 0);
        for (int i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            sum += temp;
            v[i] = temp;
        }
        
        sort(v.begin(), v.end());

        // x <= sum - (v[i] + v[j]) <= y
        // sum - x >= v[i] + v[j] >= sum - y
        // lb = sum - y - v[i], ub = sum - x - v[i]

        for ( int i = 0; i < n; i++) {
            long long lb = sum - y - v[i], ub = sum - x - v[i];
            
            auto start = lower_bound(v.begin() + i + 1, v.end(), lb);
            auto end = upper_bound(v.begin() + i + 1, v.end(), ub);
            
            ans += (end-start);
        }

        cout << ans << endl;

    }
    return 0;
}