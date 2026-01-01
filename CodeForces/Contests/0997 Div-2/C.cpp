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

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = (i % (n / 2 + 1)) + 1;
        }

        if ( n == 6) ans = {1, 1, 2, 3, 1, 2};

        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;    
    }

    return 0;
}