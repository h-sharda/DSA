#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int check(vector<vector<int>> &v, vector<int> &visited, int col, int &ans){

    int n = v.size();
    if ( col == -1) return n + 1;

    int target = n - col;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (v[i][col] == target) {
            visited[i] = true;
            ans = max(target, check(v, visited, col-1, ans));
            visited[i] = false;
        }
    }

    return target;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> v(n, vector<int>(n));
        vector<int> visited(n);

        for (int i =0; i <n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        for (int j = n-2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                v[i][j] += v[i][j+1];
            }
        }
        int ans = 1;
        check(v, visited, n-1, ans);

        cout << ans << endl;
    }

    return 0;
}