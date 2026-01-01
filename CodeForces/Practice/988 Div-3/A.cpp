#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int maxScore(vector<int> &nums) {
    int n = nums.size();
    int ans =0;
    vector<int> v(n+1, 0);
    for ( int i: nums) v[i]++;
    for ( int i: v) ans += i/2;
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

        int ans = maxScore(v);
        cout << ans << endl;
    }

    return 0;
}