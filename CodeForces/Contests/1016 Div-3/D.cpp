#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long num(int n, int x, int y) {
    
    if(n == 1) {
        if(x == 1 && y == 1) return 1;
        if(x == 2 && y == 2) return 2;
        if(x == 2 && y == 1) return 3;
        if(x == 1 && y == 2) return 4;
    }

    long long half = 1 << (n - 1); 
    long long blockSize = half * half; 

    if(x <= half && y <= half) return num(n - 1, x, y);
    else if(x > half && y > half) return num(n - 1, x - half, y - half) + blockSize;
    else if(x > half && y <= half) return num(n - 1, x - half, y) + 2 * blockSize;
    else return num(n - 1, x, y - half) + 3 * blockSize;

}

pair<int, int> coords(int n, long long d) {
    
    if(n == 1) {
        if(d == 1) return {1, 1};
        if(d == 2) return {2, 2};
        if(d == 3) return {2, 1};
        if(d == 4) return {1, 2};
    }
    long long half = 1 << (n - 1);
    long long blockSize = half * half;
    
    if(d <= blockSize) return coords(n - 1, d);
    else if(d <= 2 * blockSize) {
        pair<int, int> sub = coords(n - 1, d - blockSize);
        return {sub.first + half, sub.second + half};
    } else if(d <= 3 * blockSize) {
        pair<int, int> sub = coords(n - 1, d - 2 * blockSize);
        return {sub.first + half, sub.second};
    } else {
        pair<int, int> sub = coords(n - 1, d - 3 * blockSize);
        return {sub.first, sub.second + half};
    }
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        while (q--) {
            string q;
            cin >> q;
            
            if ( q == "->") {
                int x, y;
                cin >> x >> y;

                cout << num(n, x, y) << endl;
            } else {
                long long d;
                cin >> d;
                pair<int, int> ans = coords(n, d);
                cout << ans.first << " " << ans.second << endl;
            }
        }
    }

    return 0;
}