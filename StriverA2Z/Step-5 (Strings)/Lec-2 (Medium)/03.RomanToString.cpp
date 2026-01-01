// Leetcode: 13. Roman to Integer (Easy)
// Link: https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    static unordered_map<char, int> nums;
    int romanToInt(string s) {
        int ans = 0, i=0;
        while (i< s.size() ){
            if (i< s.size()-1 && nums[s[i]] < nums[s[i+1]]) {
                ans += nums[s[i+1]] - nums[s[i]];
                i+=2;
            } else ans+= nums[s[i++]];
        }
        return ans;
    }
};

unordered_map<char, int> Solution::nums = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.romanToInt(s) << endl;
    }
    return 0;
}