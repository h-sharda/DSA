// Problem: 1408. String Matching in an Array (Easy)
// Link: https://leetcode.com/problems/string-matching-in-an-array

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for (int i =0; i < n; i++) {
            string str = words[i];
            int len = str.size();
            for (int j = 0; j < n; j++) {
                if ( i == j || words[j].size() < len ) continue;
                if ( words[j].find(str) != string::npos ) {
                    ans.push_back(str);
                    break;
                }
            }
        }

        return ans;
    }
};