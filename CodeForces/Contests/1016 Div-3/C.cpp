#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return (n == 2);
    
    for (long long i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }
    
    return true;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int x, k;
        cin >> x >> k;

        bool prime = false;

        if ( k == 1) prime = isPrime(x);
        else if (x == 1) {
            if (k == 2) prime = isPrime(11);
            else if (k == 3) prime = isPrime(111);
            else if (k == 4) prime = isPrime(1111);
            else if (k == 5) prime = isPrime(11111);
            else if (k == 6) prime = isPrime(111111);
            else prime = isPrime(1111111);
        }
        
        if (prime) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
