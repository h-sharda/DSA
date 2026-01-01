#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int solve(vector <pair<int, int>> &hurdles, vector <pair<int, int>> &powerUps, int L){
    int ans = 0;
    int i =0, j =0, power =1;

    priority_queue<int> pq;

    while ( j < hurdles.size() ) {
        int start = hurdles[j].first - 1;
        int target = hurdles[j].second - hurdles[j].first + 2;
        while (i < powerUps.size() && powerUps[i].first <= start){
            pq.push(powerUps[i++].second);
        }
        while (power < target){
            if (pq.empty()) return -1;
            power += pq.top();
            pq.pop();
            ans++;
        }
        j++;
    }

    return ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, m, L;
        cin >> n >> m >> L;

        vector <pair<int, int>> hurdles(n);
        for ( int i =0; i < n ; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            hurdles[i] = {temp1, temp2};
        }

        vector <pair<int, int>> powerUps(m);
        for ( int i =0; i < m ; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            powerUps[i] = {temp1, temp2};
        }

        int ans = solve(hurdles, powerUps, L);
        cout << ans << endl;
    }

    return 0;
}