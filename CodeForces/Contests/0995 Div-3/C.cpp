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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> v(m, 0);
        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            v[i] = temp;
        }

        vector<int> q(k, 0);
        for (int i = 0; i < k; i++) {
            int temp;
            cin >> temp;
            q[i] = temp;
        }
        
        if (k == n) cout << string(m, '1') << endl;
        else if (k == n-1) {
            int xorr = 0;
            for ( int i = 0; i < k; i++) xorr ^= q[i];
            for ( int i = 1; i <= n; i++) xorr ^= i;
            
            string ans;
            for ( int i =0; i< m; i++) {
                if (v[i] != xorr) ans.push_back('0');
                else ans.push_back('1');
            }
            cout << ans << endl;
        }
        else cout << string(m, '0') << endl;
    }
    return 0;
}