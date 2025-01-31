// Date: 09/01/2025
// Number: 2185. Counting Words With a Given Prefix (Easy)
// link: https://leetcode.com/problems/counting-words-with-a-given-prefix/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isValid (string &a, string &pref) {
        int n = pref.size(), m = a.size();
        if ( m < n ) return false;
        for (int i =0; i < n; i++) if (pref[i] != a[i]) return false;
        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string &s: words) if (isValid(s, pref)) ans++;
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
        vector<string> words(n);
        for (string &s: words) cin >> s;
        string pref;
        cin >> pref;
        Solution sol;
        cout << sol.prefixCount(words, pref) << endl;
    }
    return 0;
}