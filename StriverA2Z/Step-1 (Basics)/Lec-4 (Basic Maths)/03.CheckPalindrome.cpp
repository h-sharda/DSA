// Leetcode: 9. Palindrome Number (Easy)
// link: https://leetcode.com/problems/palindrome-number/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int n =str.size();
        for (int i =0; i < n; i++) {
            if (str[i] != str[n-i-1]) return false;
        }
        return true;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        Solution ob;
        cout << ob.isPalindrome(x) << endl;
    }
    return 0;
}