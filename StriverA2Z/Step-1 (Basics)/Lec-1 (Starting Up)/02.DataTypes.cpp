// GFG: Data Type (Basic)
// link: https://www.geeksforgeeks.org/problems/data-type-1666706751/1

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int dataTypeSize(string str) {
        if (str == "Character") return sizeof(char);
        if (str == "Integer") return sizeof(int);
        if (str == "Long") return sizeof(long);
        if (str == "Float") return sizeof(float);
        if (str == "Double") return sizeof(double);
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends