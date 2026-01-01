#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(vector<long long> &a, vector<long long> &b, long long profit, long long k) {
    int n = a.size();

    return true;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;


        long long low = INT_MAX, high = INT_MIN;
        
        vector<long long> a(n, 0);
        for (int i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            low = min(temp, low);
            a[i] = temp;
        }

        vector<long long> b(n, 0);
        for (int i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            high = max(temp, high);
            b[i] = temp;
        }

        low *= n, high *= n;
        long long ans = 0;

        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            if ( isValid(a, b, mid, k) ) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        cout << ans << endl;

    }
    return 0;
}