#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> smallest(vector<int> &nums) {
    vector <int> ans;

    return ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector <int> v(n,0);
        for ( int i =0; i < n ; i++) {
            int temp;
            cin >> temp;
            v[i] = temp;
        }

        vector<int> ans = smallest(v);
        for ( int &i: ans) cout << i << " ";
        cout << endl;
    }

    return 0;
}