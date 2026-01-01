// GFG: Armstrong Number (Easy)
// link: https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    bool armstrongNumber(int n) {
        int a = n % 10;
        int b = (n % 100)/10;
        int c = n/100;
        
        return n == a*a*a + b*b*b + c*c*c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        bool flag = ob.armstrongNumber(n);
        if (flag) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
