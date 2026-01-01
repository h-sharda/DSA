// Leetcode: 921. Minimum Add to Make Parentheses Valid (Medium)
// link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, open = 0, n = s.size();
        for (int i =0; i < n; i++) {
            if ( s[i] == '(') open++;
            else if ( s[i] == ')' && open > 0) open--;
            else ans++;            
        }

        return ans + open;
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
        cout << obj.minAddToMakeValid(s) << "\n";
    }
    return 0;
}