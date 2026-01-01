// GFG: Union of Two Sorted Arrays with Duplicate Elements (Medium)
// link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        vector<int> ans = {min(a[0], b[0])};
        
        int n = a.size(), m = b.size();
        
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (a[i] == ans.back()) i++;
            else if (b[j] == ans.back()) j++;
            else if (a[i] <= b[j]) ans.push_back(a[i++]); 
            else ans.push_back(b[j++]);
        }
        
        while ( i < n ) {
            if (a[i] == ans.back()) i++;
            else ans.push_back(a[i++]);
        }
        
        while ( j < m ) {
            if (b[j] == ans.back()) j++;
            else ans.push_back(b[j++]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends