// Leetcode: 1781. Sum of Beauty of All Substrings (Medium)
// Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            int v[26] = {0};
            for (int j = i; j < n; j++) {
                v[s[j]-'a']++;
                int maxx = INT_MIN, minn = INT_MAX;
                for (int k =0; k < 26; k++) {
                    if (v[k] != 0) {
                        maxx = max(maxx, v[k]);
                        minn = min(minn, v[k]);
                    }
                }
                ans += maxx - minn;
            }
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
        cout << obj.beautySum(s) << endl;      
    }
    return 0;
}