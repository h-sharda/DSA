#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long cal(vector<vector<long long>> &v, char dir, int x, int y) {
    long long sum = 0;
    int n = v.size(), m = v[0].size();
    
    if (dir == 'D') {
        for (int i =0; i < m; i++) sum += v[x][i];
    } else {
        for (int i =0; i < n; i++) sum += v[i][y];
    }

    return -sum;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        string path;
        cin >> path;

        vector<vector<long long>> v(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        int x = 0, y =0;
        for (int i =0; i < n + m -1; i++) {
            v[x][y] = cal(v, path[i], x, y);
            if (path[i] == 'D') x++;
            else y++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}