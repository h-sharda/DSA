// Code360: Nth Fibonacci Number (Easy)
// link: https://www.naukri.com/code360/problems/nth-fibonacci-number_74156

#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin >> n;

        if (n == 1 || n == 2) {
                cout << 1;
                return 0;
        }

        int fib, prev1 = 1, prev2 = 1;
        
        for (int i =2; i< n; i++){
                fib = prev1 + prev2;
                prev2 = prev1;
                prev1 = fib;
        }

        cout << fib;
        return 0;
}