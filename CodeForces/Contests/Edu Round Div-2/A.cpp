
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
        long long n;
        cin >> n;
 
        long long ans = 1;
        while ( n >= 4) {
            n /= 4;
            ans *= 2;
        }
 
        cout << ans << endl;
    }
    return 0;
}