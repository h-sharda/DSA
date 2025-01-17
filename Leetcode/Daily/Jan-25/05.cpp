// Date: 05/01/2025
// Number: 2381. Shifting Letters II (Medium)
// link: https://leetcode.com/problems/shifting-letters-ii/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n + 1, 0);
        
        for (const auto &it: shifts) {
            if (it[2] == 1) {
                shift[it[0]]++;
                shift[it[1]+1]--;
            } else {
                shift[it[0]]--;
                shift[it[1]+1]++;
            }
        }

        int change = 0;
        for (int i =0; i < n; i++) {
            change += shift[i];
            change %= 26;
            int ch = s[i] - 'a' + change;
            ch = ((ch % 26) + 26) % 26;
            s[i] = ch + 'a';
        }

        return s;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> shifts(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> shifts[i][0] >> shifts[i][1] >> shifts[i][2];
        }
        Solution sol;
        cout << sol.shiftingLetters(s, shifts) << endl;
    }
    return 0;
}