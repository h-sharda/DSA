#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

pair<int, int> points(vector<int> &nums) {
    int n = nums.size(), gridSize = n-2;
    unordered_map<int, int> umap;
    for ( int i: nums){
        int comp = gridSize/i;
        if ( comp*i == gridSize){
            if ( umap.find(comp) != umap.end() ) return {comp, i};
        }
        umap[i]++;
    }
    return {-1, -1};
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector <int> v(n,0);
        for ( int i =0; i < n ; i++) {
            int temp;
            cin >> temp;
            v[i] = temp;
        }

        pair<int, int> ans = points(v);
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}