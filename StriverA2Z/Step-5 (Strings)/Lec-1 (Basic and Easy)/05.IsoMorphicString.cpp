// Leetcode: 205. Isomorphic Strings (Easy)
// Link: https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map <char, char> umap1, umap2;
        for (int i =0; i < n; i++) {
            if ( umap1.contains(s[i]) || umap2.contains(t[i]) ) {
                if (t[i] != umap1[s[i]] || s[i] != umap2[t[i]]) return false;
            } else {
                umap1[s[i]] = t[i];
                umap2[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        Solution obj;
        cout << obj.isIsomorphic(s, t) << endl;
    }
    return 0;
}