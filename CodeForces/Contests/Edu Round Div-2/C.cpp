#include <bits/stdc++.h>
using namespace std;
 
void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        
        int uniquePos = -1;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if ( v[i] != -1 && v[i] != 1) uniquePos = i;
        }
 
        set<int> s;
        s.insert(0);
 
        if ( uniquePos == -1) {
            int one = 0, _one = 0;
            for ( int i = 0; i < n; i++) {
                if ( v[i] == 1) {
                    _one = 0;
                    one++;
                    s.insert(one);
                } else {
                    one = 0;
                    _one++;
                    s.insert(-_one);
                }
            }
            cout << s.size() << endl;
            for (int i: s) cout << i << " "; 
            cout << endl;
        } else {
            int one = 0, _one = 0;
            for ( int i = 0; i < uniquePos; i++) {
                if ( v[i] == 1) {
                    _one = 0;
                    one++;
                    s.insert(one);
                } else {
                    one = 0;
                    _one++;
                    s.insert(-_one);
                }
            }
 
            int maxx1 = 0, minn1 = 0, sum = 0;
            for (int i = uniquePos-1; i >= 0; i--){
                if (v[i] == 1) sum++;
                else sum--;
                maxx1 = max(maxx1, sum);
                minn1 = min(minn1, sum);
            }
            
            int maxx2 = 0, minn2 = 0; sum = 0;
            for ( int i = uniquePos+1; i < n; i++) {
                if (v[i] == 1) sum++;
                else sum--;
                maxx2 = max(maxx2, sum);
                minn2 = min(minn2, sum);                
            }            
 
            int unique = v[uniquePos];
            for ( int i = minn1+minn2; i <= maxx1+maxx2; i++) {
                s.insert(unique + i);
            }
 
            one = 0, _one = 0;
            for ( int i = uniquePos+1; i < n; i++) {
                if ( v[i] == 1) {
                    _one = 0;
                    one++;
                    s.insert(one);
                } else {
                    one = 0;
                    _one++;
                    s.insert(-_one);
                }
            }
 
            cout << s.size() << endl;
            for (int i: s) cout << i << " "; 
            cout << endl;            
        }
    }
 
    return 0;
}