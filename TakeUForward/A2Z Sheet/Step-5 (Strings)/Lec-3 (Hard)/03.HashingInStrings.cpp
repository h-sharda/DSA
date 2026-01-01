// GFG: Index of the First Occurrence of pattern in a text
// link: https://www.geeksforgeeks.org/problems/index-of-the-first-occurrence-of-pattern-in-a-text/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        auto pos = text.find(pat);
        return pos == string::npos ? -1 : pos;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends