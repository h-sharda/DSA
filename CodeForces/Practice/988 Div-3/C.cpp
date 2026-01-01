#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> favPermutation(int n){
    return {-1};
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector <int> ans = favPermutation(n);

        for ( int i: ans) cout << i << " ";
        cout << endl;
    }

    return 0;
}