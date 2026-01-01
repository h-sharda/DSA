// GFG: Print 1 To N Without Loop (Basic)
// link: https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void print1toN(int n) {
    if (n == 0) return;
    print1toN(n - 1);
    cout << n << " ";
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        print1toN(n);
        cout << endl;
    }
    return 0;
}