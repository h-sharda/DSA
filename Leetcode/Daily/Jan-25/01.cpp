// Date: 01/01/2025
// Number: 1422. Maximum Score After Splitting a String (Easy)
// link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), maxx = INT_MIN, curr0 = 0, curr1 = 0;

        for (int i = 0; i < n-1; i++) {
            if (s[i] == '0') curr0++;
            else curr1++;
            maxx = max(maxx, curr0 - curr1);
        }
        if (s.back() == '1') curr1++;

        return maxx + curr1;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution sol;
        cout << sol.maxScore(s) << endl;      
    }
    return 0;
}