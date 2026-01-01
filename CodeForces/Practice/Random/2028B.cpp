#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long solve (long long n , long long b, long long c) {
    if ( b == 0 && c < n-2) return -1;

    if ( b == 0 ){
        if ( c >= n ) return n;
        else return n-1;
    }

    if ( (n-c+b-1)/b < 0 ) return n;
    return n - (n-c+b-1)/b;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        long long n, b, c;
        cin >> n >> b >> c;

        long long ans = solve(n , b, c);
        cout << ans << endl;
    }
    return 0;
}