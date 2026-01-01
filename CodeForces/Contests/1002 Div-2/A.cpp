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

        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> b(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        set<int> s;
        for (int i =0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s.insert(a[i]+b[j]);
            }
        }

        if (s.size() >= 3) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    return 0;
}