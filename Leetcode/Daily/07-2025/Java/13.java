// Problem: 2410. Maximum Matching of Players With Trainers (Medium)
// Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers

class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);

        int n = players.length, m = trainers.length;
        int i = 0, j =0, ans = 0;

        while ( i < n && j < m) {
            if (players[i] <= trainers[j]) {
                i++;
                j++;
                ans++;
            } else j++;
        }

        return ans;        
    }
}