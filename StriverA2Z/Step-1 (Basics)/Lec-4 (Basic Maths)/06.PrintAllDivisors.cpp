// GFG: Sum of all divisors from 1 to n (Easy)
// link: https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int sumOfDivisors(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += i*(n/i);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
