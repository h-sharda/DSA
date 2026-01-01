#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int solve_test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // For k subarrays, k/2 of them will be in array b
    // We want to minimize the first position where bi != i
    // Strategy: Try to match as many initial positions as possible
    
    // We need at least k partitions, so we'll try to put the smallest
    // possible values in even-indexed partitions to maximize matching
    vector<int> b;
    
    // Sort first k/2 minimum values to try to match positions
    vector<int> min_vals;
    for (int i = 0; i < n; i++) {
        min_vals.push_back(a[i]);
    }
    sort(min_vals.begin(), min_vals.end());
    
    // Take first k/2 elements that can match positions 1,2,3,...
    int pos = 0;
    for (int i = 0; i < k/2; i++) {
        // Find first number that could match current position
        while (pos < min_vals.size() && min_vals[pos] <= i + 1) {
            pos++;
        }
        if (pos > 0) {
            pos--;
            b.push_back(min_vals[pos]);
            pos++;
        } else {
            // If we can't match anymore, add largest values
            b.push_back(min_vals.back());
        }
    }
    
    // Add 0 at the end as required
    b.push_back(0);
    
    // Find first mismatch
    for (int i = 0; i < b.size(); i++) {
        if (b[i] != i + 1) {
            return i + 1;
        }
    }
    
    return b.size();
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        cout << solve_test_case() << endl;
    }

    return 0;
}