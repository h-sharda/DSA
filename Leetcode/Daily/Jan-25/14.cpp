// Date: 14/01/2025
// Number: 2657. Find the Prefix Common Array of Two Arrays (Medium)
// link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), common = 0;
        vector<int> ans(n), v(n+1);

        for (int i =0; i < n; i++) {
            if (v[A[i]] == 1) common++;
            v[A[i]]++;
            if (v[B[i]] == 1) common++;
            v[B[i]]++;
            
            ans[i] = common;
        }

        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }
        Solution s;
        vector<int> ans = s.findThePrefixCommonArray(A, B);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}