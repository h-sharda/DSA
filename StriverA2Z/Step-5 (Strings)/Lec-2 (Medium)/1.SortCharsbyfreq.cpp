// Leetcode: 451. Sort Characters By Frequency (Medium)
// Link: https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    string frequencySort(string s) {
        
        vector<pair<int, char>> v(128);
        for (int i =0; i< 128; i++) v[i].second = i;
        for (char &ch: s) v[ch].first++;

        sort(v.begin(), v.end());

        string ans;
        for (int i = 127; i >=0 ; i--) {
            int len = v[i].first;
            if ( len == 0 ) break;
            char ch = v[i].second;
            ans += string(len, ch);
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
        cout << obj.frequencySort(s) << endl;
    }
    return 0;
}