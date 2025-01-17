// Leetcode: 796. Rotate String (Easy)
// link: https://leetcode.com/problems/rotate-string/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s+s).find(goal) != string::npos;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s, goal;
        cin >> s >> goal;
        Solution obj;
        cout << obj.rotateString(s, goal) << endl;
    }
    return 0;
}