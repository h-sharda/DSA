// Date: 17/01/2025
// Number: 2683. Neighboring Bitwise XOR (Medium)
// link: https://leetcode.com/problems/neighboring-bitwise-xor/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size(), num = 0;
        for (int i =0; i < n-1; i++) num ^= derived[i];
        return num == derived[n-1];
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> derived(n);
        for (int i = 0; i < n; i++) cin >> derived[i];
        Solution sol;
        cout << sol.doesValidArrayExist(derived) << endl;
    }
    return 0;
}