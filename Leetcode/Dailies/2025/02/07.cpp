// Problem: 3160. Find the Number of Distinct Colors Among the Balls (Medium)
// Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> ballWithColor, colorOfBall;

        for (auto &it: queries) {
            int ball = it[0], color = it[1];
            int prevColor = colorOfBall[ball];
            if (prevColor) {
                ballWithColor[prevColor]--;
                if (ballWithColor[prevColor] == 0) ballWithColor.erase(prevColor);
            }

            ballWithColor[color]++;
            colorOfBall[ball] = color;

            ans.push_back(ballWithColor.size());
        }

        return ans;
    }
};