#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> solve (int n, vector<int> &nums, unordered_set<int> &uset) {
    
    vector<int> uniqueVals;
    for ( int i =1; i <= n; i++) {
        if ( uset.find(i) == uset.end()) uniqueVals.push_back(i);
    }

    uset.clear();
    vector<int> ans;
    for ( int i =0; i < nums.size(); i++ ) {
        if ( uset.find(nums[i]) != uset.end() ) {
            ans.push_back(uniqueVals.back());
            uniqueVals.pop_back();
        } else ans.push_back(nums[i]);

        uset.insert(nums[i]);
    }
    return ans;
}
 
int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        unordered_set<int> uset;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
            uset.insert(temp);
        }
        
        vector<int> ans = solve(n, v, uset);

        for (int i=0; i<n; i++) cout << ans[i] << " ";
        cout << endl;
        
    }
    return 0;
}
