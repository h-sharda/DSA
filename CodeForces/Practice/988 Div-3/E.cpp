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
        
        int f, prevF = -1, temp = n-1;
        string ans;
        bool possible = true;

        while ( temp > 0 ){

            cout << "? " << n-temp << " " << n << endl;
            cout.flush();
            cin >> f; 
            if ( f == 0 ) {
                cout << "! IMPOSSIBLE" << endl;
                possible = false;
                break;
            }
            if ( prevF != -1) {
                if ( f == prevF ) ans.push_back('1');
                else ans.push_back('0');
            }

            prevF = f, temp--;
        }
        if(possible) cout << "! " << ans << "01" << endl;
    }

    return 0;
}