// Leetcode: 14. Longest Common Prefix (Easy)
// link: https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre;
        int n = strs.size(), k = strs[0].size();
        for (int i =0; i < k; i++){
            char ch = strs[0][i];
            bool isCommon = true;
            for (int j =1; j < n; j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    isCommon = false;
                    break;
                }
            }
            if (isCommon ) pre.push_back(ch);
            else break;
        }
        return pre;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        
    }
    return 0;
}