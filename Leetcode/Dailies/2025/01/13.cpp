// Date: 13/01/2025
// Number: 3223. Minimum Length of String After Operations (Medium)
// link: https://leetcode.com/problems/minimum-length-of-string-after-operations/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), ans = 0, v[26] = {0};

        for (int i =0; i < n; i++) v[s[i]-'a']++;
        for (int i =0; i < 26; i++) {
            if (v[i] == 0) continue;
            ans += (v[i] % 2 ? 1 : 2);
        }
        
        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.minimumLength(s) << endl;
    }
    return 0;
}