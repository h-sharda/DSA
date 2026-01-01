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
        vector<int> v(n, 0);
        bool all0 = true, togetherNon0= true;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;

            if ( temp != 0) all0 = false;
            v[i] = temp;
        }

        for ( int i =0; i< n; i++) {
            if ( v[i] != 0) {
                while (i < n && v[i] != 0) i++;
                while (i < n && v[i] == 0) i++;
                if (i != n) togetherNon0 = false;
            }
        }
        
        if (all0) cout << 0;
        else if (togetherNon0) cout << 1;
        else cout << 2;
        cout << endl;
    }
    return 0;
}