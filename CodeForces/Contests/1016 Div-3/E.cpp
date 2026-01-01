#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(vector<int> &nums, int minMEX, int k) {
    if ( minMEX == 0 ) return true;
    int n = nums.size();

    int found = 0;
    vector<bool> seen(minMEX, false);

    for (int i = 0; i < n && k > 0; i++) {
        if(nums[i] < minMEX && !seen[nums[i]]) {
            seen[nums[i]] = true;
            found++;
        }

        if(found == minMEX) {
            k--;
            seen.assign(minMEX, false);
            found = 0;
        }
    }

    return k == 0;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        int low = 0, high = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            high = max(high, v[i]);
        }

        high++;

        while ( low <= high) {
            int mid = low + (high-low)/2;
            if (isValid(v, mid, k)) low = mid + 1;
            else high = mid - 1;
        }

        cout << high << endl;
    }
    return 0;
}