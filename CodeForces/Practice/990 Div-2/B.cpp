#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void leastPerumtations( string &str ){
    vector<pair<int, char>> v(26);
    for (int i =0; i < 26; i++) v[i].second = i+'a';
    for ( char &ch: str) v[ch-'a'].first++;
    
    sort(v.begin(), v.end());
    char maxx = v[25].second, minn;
    for ( int i =0; i < 26; i++) {
        if (v[i].first != 0) {
            minn = v[i].second;
            break;
        }
    }
    
    for ( int i =0; i< str.size(); i++){
        if ( str[i] == minn) {
            str[i] = maxx;
            break;
        }
    }
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string str;
        cin >> str;
        leastPerumtations(str);
        cout << str << endl;
    }

    return 0;
}