// Date: 06/01/2025
// Number: 1769. Minimum Number of Operations to Move All Balls to Each Box (Medium)
// link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), ballR = 0, ballL = 0, costR = 0, costL = 0;

        vector<int> ans(n);

        for (int i =1; i < n; i++) {
            if (boxes[i] == '1') {
                costR += i;
                ballR++;
            }
        }
        ans[0] = costR;

        for (int i = 1; i < n; i++) {
            
            if (boxes[i-1] == '1') ballL++;
            costL += ballL;
            costR -= ballR;
            if (boxes[i] == '1') ballR--;

            ans[i] = costR + costL;

        }
        
        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string boxes;
        cin >> boxes;
        Solution s;
        vector<int> ans = s.minOperations(boxes);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}