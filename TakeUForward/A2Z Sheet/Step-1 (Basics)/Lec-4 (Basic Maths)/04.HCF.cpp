// GFG: LCM and GCD (Basic)
// link: https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int hcf (int a, int b){
        if (a > b) swap(a, b);
        if (b % a == 0) return a;
        return hcf(b % a, a);
    }
    
    vector<int> lcmAndGcd(int a, int b) {
        int HCF = hcf(a, b);
        int LCM = (1LL * a * b) / HCF;
        
        return {LCM, HCF};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
