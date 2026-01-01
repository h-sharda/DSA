#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int mex(vector<int> &nums) {
    int minn = 0, n = nums.size();
    while (true) {
        for (int i = 0; i < n; i++) {
            if ( nums[i] == minn ) {
                minn++;
                break;
            }
            if (i == n-1) return minn;
        }
    }
    return minn;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> ans;
        ans.push_back(0);

        for ( int i = 2; i < n; i++) {
            vector<int> v;
            v.push_back(ans.back());
            if (i == y && x < i) v.push_back(ans[x-1]);
            else if (i == x && y < i) v.push_back(ans[y-1]);
            ans.push_back(mex(v));
        }

        vector<int> v;
        v.push_back(ans[0]);
        v.push_back(ans.back());
        if ( n == y) v.push_back(ans[x-1]);
        else if ( n == x) v.push_back(ans[y-1]);
        ans.push_back(mex(v));

        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
        
    }
    return 0;
}