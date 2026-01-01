// Code360: Aggresive Cows (Moderate)
// link: https://www.naukri.com/code360/problems/aggressive-cows_1082559

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(vector<int> &stalls, int k, int gap) {
    int n = stalls.size(), dist = 0;
    k--;

    for (int i = 1; i < n && k > 0; i++) {
        if (stalls[i] - stalls[i-1] + dist >= gap) {
            k--;
            dist = 0;
        } else dist += stalls[i] - stalls[i-1];
    }

    return k <= 0;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int low = 0, high = stalls.back()-stalls[0], ans = -1;

    while ( low <= high) {
        int mid = low + (high - low)/2;

        if (isValid(stalls, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }

    return ans; 

}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        cout << aggressiveCows(v, k) << endl;
    }
    return 0;
}