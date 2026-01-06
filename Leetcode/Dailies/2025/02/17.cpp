// Problem: 1079. Letter Tile Possibilities (Medium)
// Link: https://leetcode.com/problems/letter-tile-possibilities

class Solution {
public:
    int r(vector<int> &v, int size) {
        if (size == 0) return 1;
        int ans = 0;
        
        for (int &freq: v) {
            if (freq) {
                freq--;
                ans += r(v, size - 1);
                freq++;
            }
        }
        
        return ans;    
    }

    int numTilePossibilities(string tiles) {
        vector<int> v(26);
        for (char &ch: tiles) v[ch-'A']++;

        int ans = 0;
        for (int sz = 1; sz <= tiles.size(); sz++) ans += r(v, sz);

        return ans;
    }
};