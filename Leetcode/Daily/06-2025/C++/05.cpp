// Problem: 1061. Lexicographically Smallest Equivalent String (Medium)
// Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string

class Solution {
public:
    int id = 1; // starting value of component_id
    unordered_map<char, int> umap1; // letter -> componenet_id
    unordered_map<int, set<char>> umap2; // componenet_id -> list of all chars

    void populate(string &s1, string &s2) {
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            int id1 = umap1[s1[i]], id2 = umap1[s2[i]];

            if (id1 && id2) {
                for (auto ch: umap2[id2]) {
                    umap1[ch] = id1;
                    umap2[id1].insert(ch);
                }
            } else if (id1) {
                umap1[s2[i]] = id1;
                umap2[id1].insert(s2[i]);
            } else if (id2) {
                umap1[s1[i]] = id2;
                umap2[id2].insert(s1[i]);
            } else {
                umap1[s1[i]] = id;
                umap1[s2[i]] = id;
                umap2[id] = {s1[i], s2[i]};
                id++;
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string base) {
        populate(s1, s2);

        int n = base.size();
        string ans = base;
        for (int i = 0; i < n; i++) {
            int id = umap1[base[i]];
            if (id) ans[i] = *(umap2[id].begin());
        }

        return ans;
    }
};
