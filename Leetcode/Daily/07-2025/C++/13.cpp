// Problem: 2410. Maximum Matching of Players With Trainers (Medium)
// Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int n = players.size(), m = trainers.size();
        int i = 0, j =0, ans = 0;

        while ( i < n && j < m) {
            if (players[i] <= trainers[j]) i++, j++, ans++;
            else j++;
        }

        return ans;
    }
};