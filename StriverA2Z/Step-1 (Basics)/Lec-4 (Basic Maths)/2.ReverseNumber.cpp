// Leetcode: 7. Reverse Integer (Medium)
// link: https://leetcode.com/problems/reverse-integer/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;

        bool isNegative = false;
        if ( x < 0) {
            x = -x;
            isNegative = true;
        }

        int ans = 0;
        while (x > 0) {
            if (ans > INT_MAX/10) return 0;
            ans = ans*10 + x % 10;
            x /= 10;
        }
        
        return isNegative ? -ans : ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.reverse(n) << endl;
    }
    return 0;
}