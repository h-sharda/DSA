#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int minn( string a, string b, string c) {
    unordered_map<char, int> umap;
    for ( char ch: a) umap[ch]++;
    for ( char ch: b) umap[ch]++;

    int ans = 0;

    for ( char ch: c ) umap[ch]--;
    
    for ( auto it: umap){
        if (it.second > 0) ans += it.second;
    }

    return ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        cout << minn(a, b, c) << endl;
    }
    return 0;
}