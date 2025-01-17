// Code360: Check for Prime (Easy)
// link: https://www.naukri.com/code360/problems/check-prime_624934

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isPrime(int n){
    if ( n == 1 ) return false;
    for(int i = 2; i*i <= n; i++){ 
        if ( n%i == 0) return false;
    }
	return true;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << isPrime(n) << endl;        
    }
    return 0;
}