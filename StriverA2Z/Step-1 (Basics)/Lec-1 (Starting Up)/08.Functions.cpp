// GFG: Pass by Reference and Value (Easy)
// link: https://www.geeksforgeeks.org/problems/pass-by-reference-and-value/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    vector<int> passedBy(int a, int &b) {
        a++; b += 2;
        return {a, b};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        Solution obj;
        vector<int> ans = obj.passedBy(a, b);
        cout << ans[0] << " " << ans[1] << "\n";
    
        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends