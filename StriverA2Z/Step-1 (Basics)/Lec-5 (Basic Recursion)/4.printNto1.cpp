// GFG: Print N to 1 without loop (Easy)
// link: https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    void printNos(int n) {
        if (n == 0) return;
        cout << n << " ";
        printNos(n - 1);        
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNos(N);
        cout << "\n";
    
        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends