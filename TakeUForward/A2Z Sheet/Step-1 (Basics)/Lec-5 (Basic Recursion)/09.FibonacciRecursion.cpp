// Leetcode: 509. Fibonacci Number (Easy)
// link: https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int fib(int n) {
        if ( n == 0 || n == 1 ) return n;
        return fib(n-1) + fib(n-2);
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.fib(n) << endl;
    }
    return 0;
}