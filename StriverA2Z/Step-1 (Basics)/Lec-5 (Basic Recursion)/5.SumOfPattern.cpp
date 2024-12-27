// GFG: Sum of first n terms (Basic)
// link: https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int getSum (int sum, int n){
        if ( n == 0 ) return sum;
        sum += n*n*n;
        return getSum(sum, n-1);
    }
    
    int sumOfSeries(int n) {
        return getSum(0, n);
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
        cout << ob.sumOfSeries(N) << "\n";

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends