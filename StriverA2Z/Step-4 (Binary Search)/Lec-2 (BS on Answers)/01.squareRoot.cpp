// GFG: Square Root (Easy)
// link: https://www.geeksforgeeks.org/problems/square-root/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int floorSqrt(int n) {
        int low = 1, high = n/2;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (mid > (INT_MAX/mid)) high = mid - 1;
            else if (mid *mid <= n) low = mid +1;
            else high = mid-1;
        }  
        
        return high;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends