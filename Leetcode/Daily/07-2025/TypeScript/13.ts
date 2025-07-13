// Problem: 2410. Maximum Matching of Players With Trainers (Medium)
// Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers

function matchPlayersAndTrainers(players: number[], trainers: number[]): number {
    players.sort((a, b) => a - b);
    trainers.sort((a, b) => a - b);

    let n = players.length, m = trainers.length;
    let i = 0, j =0, ans = 0;

    while ( i < n && j < m) {
        if (players[i] <= trainers[j]) {
            i++;
            j++;
            ans++;
        } else j++;
    }

    return ans;    
};