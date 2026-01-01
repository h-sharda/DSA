#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        int n = s.size();
        
        vector<int> v(10);
        for (char &ch: s) v[ch-'0']++;

        for (int i =1; i < n; i++) {
            if (s[i] != s[i-1] && (s[i]-'0') == v[s[i]-'0'] && (s[i-1]-'0') == v[s[i-1]-'0']) return s.substr(i-1, 2);
        }

        return "";
    }
};