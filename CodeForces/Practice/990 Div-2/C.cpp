#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int findMax(vector<vector<int>> &nums) {
    int n = nums[0].size();
    int ans = 0;

    for ( int i =0; i < n; i++){
        if ( nums[0][i] > nums[1][i] ) {
            ans += nums[0][i];
            nums[0][i] = INT_MIN;
        } else {
            ans += nums[1][i];
            nums[1][i] = INT_MIN;            
        }
    }

    int maxx = INT_MIN;
    for ( int i =0; i < n; i++){
        maxx = max({maxx, nums[0][i], nums[1][i]});
    }    

    return ans+maxx;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector <vector<int>> v(2, vector<int>(n));
        for ( int i =0; i < n ; i++) {
            int temp;
            cin >> temp;
            v[0][i] = temp;
        }
        for ( int i =0; i < n ; i++) {
            int temp;
            cin >> temp;
            v[1][i] = temp;
        }

        int ans = findMax(v);
        cout << ans << endl;
    }

    return 0;
}