// GFG: Find nth root of m
// link: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        
        while (low <= high) {
            
            int mid = low + (high-low)/2;
            
            int prod = 1;
            for (int i = 0; i < n; i++) {
                if (prod > INT_MAX/mid) {
                    prod = -1;
                    break;
                } else prod *= mid;
            }
            
            if ( prod == m ) return mid;
            else if ( prod == -1 || prod > m) high = mid-1;
            else low = mid +1;
            
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends