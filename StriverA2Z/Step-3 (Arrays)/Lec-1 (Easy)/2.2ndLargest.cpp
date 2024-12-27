// GFG: Second Largest (Easy)
// link: https://www.geeksforgeeks.org/problems/second-largest3735/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int maxx1 = INT_MIN, maxx2 = INT_MIN;
        for (int &i: arr){
            if (i > maxx1) {
                maxx2 = maxx1;
                maxx1 = i;
            } else if (i > maxx2 && i != maxx1) maxx2 = i;
        }
        return maxx2 == INT_MIN ? -1 : maxx2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends