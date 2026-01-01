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
        int n;
        cin >> n;
        vector<int> v1(n, 0);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v1[i] = temp;
        }
        vector<int> v2(n, 0);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v2[i] = temp;
        }
        
        int ans = 0;

        for ( int i =0; i < n-1; i++) {
            if (v1[i] > v2[i+1]) ans += (v1[i] - v2[i+1]);
        }

        ans += v1.back();

        cout << ans << endl;

    }
    return 0;
}