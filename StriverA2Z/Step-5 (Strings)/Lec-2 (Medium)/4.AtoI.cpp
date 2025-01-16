// Leetcode: 8. String to Integer (atoi) (Medium)
// Link: https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        bool sign = false;

        int i = 0, n = s.size();

        while (s[i] == ' ') i++;
        
        if (s[i] == '-') sign = true;
        if (s[i] == '+' || s[i] == '-') i++;

        while (i < n ) {
            if (!isdigit(s[i])) break;

            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i] > '7')){
                return sign ? INT_MIN : INT_MAX;
            }
            
            ans = ans*10 + (s[i]-'0');
            i++;
        }

        return sign ? -ans : ans;
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
        cout << obj.myAtoi(s) << endl;
    }
    return 0;
}