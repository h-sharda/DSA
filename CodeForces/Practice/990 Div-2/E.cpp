#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(vector<pair<int, int>> &cities, int minn){
    // code
    return true;
}

int maxCities (vector<pair<int, int>> &cities, pair<int, int> &coords) { 
    int low =0, high = cities.size();
    int ans= -1;
    while ( low <= high) {
        int mid = low + (high - low)/2;
        if (isValid(cities, mid)){
            ans = mid;
            low = mid + 1;
        } else high = mid -1;
    }
    return ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector <pair<int, int>> v(n);
        for ( int i =0; i < n ; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            v[i] = {temp1, temp2};
        }

        pair <int, int> coords;
        int maxx = maxCities(v, coords);
        
        cout << maxx << endl;
        cout << coords.first << " " << coords.second << endl;
    }

    return 0;
}