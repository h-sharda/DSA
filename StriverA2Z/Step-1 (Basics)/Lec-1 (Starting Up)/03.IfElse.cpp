// GFG: Decision making in Java (Basic)
// link: https://www.geeksforgeeks.org/problems/java-if-else-decision-making0924/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    string compareNM(int n, int m){
        if ( n < m ) return "lesser";
        else if ( n == m ) return "equal";
        else return "greater";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m ; cin>>n>>m;
        Solution obj;
        cout<<obj.compareNM(n,m)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends