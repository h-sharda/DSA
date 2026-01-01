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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(2, 0));
        for (int i =0; i < n; i++) {
            cin >> v[i][0] >> v[i][1];
        }

        int perimeter = 4 * k;

        for (int i = 1; i < n; i++) {
            perimeter += 4 * k;
            int overlap = 2*(k-v[i][0]) + 2*(k-v[i][1]); 
            if (overlap > 0) perimeter -= overlap;
        }

        cout << perimeter << endl;
        
    }
    return 0;
}
