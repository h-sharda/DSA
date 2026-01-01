#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(vector<int> &nums){
    int n = nums.size();
    long long sum = 0, sumO = 0, sumE = 0;
    
    for ( int i =0; i < n; i++) {
        sum += nums[i];
        if (i % 2 ) sumO += nums[i];
        else sumE += nums[i];
    }

    if ( sum % n != 0 ) return false;
    long long avg = sum/n;
    
    int avgE = sumE/((n+1)/2), avgO = sumO/(n/2);
    
    return avg == avgO && avg == avgE;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for ( int i =0; i < n ; i++) {
            int temp;
            cin >> temp;
            v[i] = temp;
        }

        if ( isValid(v) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}