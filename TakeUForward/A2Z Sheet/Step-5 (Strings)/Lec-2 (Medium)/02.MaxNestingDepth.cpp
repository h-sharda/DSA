// Leetcode: 1614. Maximum Nesting Depth of the Parentheses (Easy)
// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int ans = 0, open = 0;

        for (int i =0; i < n; i++) {
            if ( s[i] == '(') open++;
            else if (s[i] == ')') open--;

            ans = max(ans, open);
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
        cout << obj.maxDepth(s) << endl;
    }
    return 0;
}