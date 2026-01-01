// Leetcode: 242. Valid Anagram (Easy)
// Link: https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> v1(26), v2(26);

        for (char &ch : s) v1[ch-'a']++;
        for (char &ch : t) v2[ch-'a']++;
        
        return v1==v2;
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
        cout << obj.isAnagram(s, t) << endl;
    }
    return 0;
}