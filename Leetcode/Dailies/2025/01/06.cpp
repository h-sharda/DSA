// Problem: 1769. Minimum Number of Operations to Move All Balls to Each Box (Medium)
// Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

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