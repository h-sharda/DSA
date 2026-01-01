// Leetcode: 38. Count and Say (Medium)
// link: https://leetcode.com/problems/count-and-say/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string target = countAndSay(n-1), ans;
        int len = target.size(), i = 0;
        
        while (i < len) {
            char ch = target[i];
            int count = 0;
            
            while (i < len && target[i] == ch) i++, count++;

            ans += to_string(count);
            ans.push_back(ch);

        }

        return ans;
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
        cout << obj.countAndSay(n) << "\n";
    }
    return 0;
}