// Date: 07/01/2025
// Number: 1408. String Matching in an Array (Easy)
// link: https://leetcode.com/problems/string-matching-in-an-array/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for (int i =0; i < n; i++) {
            string str = words[i];
            int len = str.size();
            for (int j = 0; j < n; j++) {
                if ( i == j || words[j].size() < len ) continue;
                if ( words[j].find(str) != string::npos ) {
                    ans.push_back(str);
                    break;
                }
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
        int n;
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        Solution sol;
        vector<string> ans = sol.stringMatching(words);
        for (string str : ans) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}