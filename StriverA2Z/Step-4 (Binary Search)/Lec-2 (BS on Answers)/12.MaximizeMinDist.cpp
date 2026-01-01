// Code360:  Minimize Max Distance to Gas Station
// link: https://www.naukri.com/code360/problems/minimise-max-distance_7541449

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(vector<int> &arr, int k, double maxDist) {
    int n = arr.size();
    for (int i = 0; i < n-1 && k >= 0; i++) {
        int dist = arr[i+1]-arr[i];
        if (dist > maxDist) {
            int stations = ceil(dist / maxDist) - 1;
            k -= stations;
        }
    }
    return k >= 0;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	sort(arr.begin(), arr.end());
    double low = 0, high = arr.back() - arr[0], ans = -1;

    while ( high - low > 1e-6) {
        double mid = (low + high ) / 2.0; 
        if (isValid(arr, k, mid)) {
            ans = mid;
            high = mid;
        } else low = mid;
    }

    // cout << ans;

    return ans;
}


int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector <int> v(n);
        for ( int i =0; i < n ; i++) {
            cin >> v[i];
        }

        cout << fixed << setprecision(6) << minimiseMaxDistance(v, k) << endl;
    }
    return 0;
}