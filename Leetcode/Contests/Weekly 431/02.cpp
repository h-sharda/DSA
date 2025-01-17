#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        
        unordered_map <char, vector<int>> umap;
        long long ans = 0;
        
        for (int i =0; i < n; i++) {
            char target = ((-1)*(s[i]-'a'-25)) + 'a';
            if (umap.contains(target)) {
                ans += i - umap[target].back();
                umap[target].pop_back();
                if (umap[target].size() == 0) umap.erase(target);
            } else umap[s[i]].push_back(i);
        }

        return ans;
    }
};