// Date: 02/01/2025
// Number: 2559. Count Vowel Strings in Ranges (Medium)
// link: https://leetcode.com/problems/count-vowel-strings-in-ranges/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isValid (string& a) {
        return (a[0] == 'a' || a[0] == 'e' || a[0] == 'i' || a[0] == 'o' || a[0] == 'u') &&
            (a.back() == 'a' || a.back() == 'e' || a.back() == 'i' || a.back() == 'o' || a.back() == 'u');
    };
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), count = 0;
    
        vector<int> v(n+1, 0);
        for (int i = 0; i < n; i++) {
            if (isValid(words[i])) count++;
            v[i+1] = count;
        }
        
        int q = queries.size();
        vector <int> ans(q, 0);
        for (int i = 0; i < q; i++) ans[i] = v[queries[i][1]+1] - v[queries[i][0]];

        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<string> words(n);
        vector<vector<int>> queries(q, vector<int>(2));
        for (int i = 0; i < n; i++) cin >> words[i];
        for (int i = 0; i < q; i++) cin >> queries[i][0] >> queries[i][1];
        Solution sol;
        vector<int> ans = sol.vowelStrings(words, queries);
        for (int i = 0; i < q; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}