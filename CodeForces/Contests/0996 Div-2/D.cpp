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
        int n, k, l;
        cin >> n >> k >> l;
        
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        double time = 0, gap = v[0];

        for (int i = 1; i < n; i++) {
            gap = max(gap, 1.0 * (v[i]-v[i-1]));
        }

        gap = max(gap, 1.0*(l - v.back()));

        time = (v[0] + (gap/k)) * 2;

        cout << round(time) << endl;
        
    }
    
    return 0;
}