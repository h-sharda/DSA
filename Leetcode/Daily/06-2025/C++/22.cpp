// Problem: 2138. Divide a String Into Groups of Size k (Easy)
// Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();

        for (int i = 0; i < n; i += k) ans.push_back(s.substr(i, k));
        ans.back() += string(k - ans.back().size(), fill);

        return ans;
    }
};