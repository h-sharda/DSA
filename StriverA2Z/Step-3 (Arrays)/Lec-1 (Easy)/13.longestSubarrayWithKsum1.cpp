// Code360: Longest Subarray With Sum K (Easy)
// link: https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size(), ans = 0, start = 0, i = 0;
    long long sum = 0;

    while (i < n) {
        if (a[i] + sum < k ) sum += a[i++];
        else if (a[i] + sum > k) sum -= a[start++];
        else {
            ans = max(ans, i-start+1);
            sum += a[i++];
        } 
    }

    return ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << longestSubarrayWithSumK(a, k) << endl;       
    }
    return 0;
}