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
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        bool ans = true;
        long long less = 0, sum = 0, need = 0, pos = -1;
        
        for (int i =0; i <n; i++) {
            if (b[i] > a[i]) {
                pos = i;
                need = b[i] - a[i];
                less++;
            }

            if (less == 2) break;
        }

        if (less >= 2) ans = false;
        else if (less == 1) {
            for (int i =0; i < n; i++) {
                if (i == pos) continue;
                if (a[i] < b[i] + need ) {
                    ans = false;
                    break;
                }
            }
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}