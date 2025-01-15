// Leetcode: 1903. Largest Odd Number in String (Easy)
// link: https://leetcode.com/problems/largest-odd-number-in-string/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int j = n-1; j >= 0; j--) if ((num[j] - '0') % 2) {
            num.resize(j+1);
            return num;
        }
        return "";
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string num;
        cin >> num;
        Solution s;
        cout << s.largestOddNumber(num) << endl;
    }
    return 0;
}