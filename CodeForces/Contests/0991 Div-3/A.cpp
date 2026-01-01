#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int maxWords(vector<string> &words, int m) {
    int ans = 0, i =0;
    while ( i < words.size() && m > 0) {
        m -= words[i].size();
        if ( m >= 0) ans++;
        i++;
    }
    return ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> words;
        for ( int i =0; i < n ; i++) {
            string str;
            cin >> str;
            words.push_back(str);
        }

        cout << maxWords(words, m) << endl;
    }
    return 0;
}