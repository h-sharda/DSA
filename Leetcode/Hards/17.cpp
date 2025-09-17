// Problem: 10. Regular Expression Matching (Hard)
// Link: https://leetcode.com/problems/regular-expression-matching

class Solution {
    int n, m;
    unordered_map<int, bool> umap;

public:
    bool isMatch(string &s, string &p, int i, int j) {
        int key = i * 21 + j;
        if (umap.contains(key)) return umap[key];
        
        if (i == n) while (j + 1 < m && p[j + 1] == '*') j += 2;

        if (i == n || j == m) return umap[key] = (i == n && j == m);
        
        if (j + 1 < m && p[j + 1] == '*') {
            if (s[i] == p[j] || p[j] == '.') 
                return umap[key] = isMatch(s, p, i + 1, j) || isMatch(s, p, i, j + 2);
            else 
                return umap[key] = isMatch(s, p, i, j + 2);
        }
        
        if (s[i] == p[j] || p[j] == '.') return umap[key] = isMatch(s, p, i + 1, j + 1);
        
        return umap[key] = false;
    }

    bool isMatch(string s, string p) {
        n = s.size(), m = p.size();
        return isMatch(s, p, 0, 0);
    }
};