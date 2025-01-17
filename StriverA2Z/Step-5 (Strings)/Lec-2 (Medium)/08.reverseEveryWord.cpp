// Leetcode: 151. Reverse Words in a String (Medium)
// link: https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int l = 0, r = 0, n = s.size();
        while ( r < n) {
            if (s[l] == ' ') l++;
            else {
                r = l;
                while (r < n && s[r] != ' ') r++;
                reverse(s.begin()+l, s.begin()+r);
                l = r;
            }
        }

        l = 0, r = 0;

        while ( r < n ) {
            while (r < n && s[r] == ' ') r++;
            while (r < n && s[r] != ' ') swap(s[l++], s[r++]);
            l++;
        }      
        
        while (s.back() == ' ') s.pop_back();

        return s;
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
        cout << obj.reverseWords(s) << endl;
    }
    return 0;
}