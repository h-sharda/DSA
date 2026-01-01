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
        long long k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        long long maxx = r2/l1;
        long long ans = 0;

        for ( long long pow = 1; pow <= maxx; pow *= k ) {
            
            long long start = l1, end = r1;

            if ( start*pow < l2 ) start = (l2 + pow - 1) / pow;
            if ( end*pow > r2 ) end = r2/pow;
            
            if (start <= end) ans += end-start+1;
        }

        cout << ans << endl;
    }
    return 0;
}