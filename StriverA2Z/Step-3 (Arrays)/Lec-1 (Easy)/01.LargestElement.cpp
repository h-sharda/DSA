// GFG: Largest Element in Array (Basic)
// link: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxx = INT_MIN;
        for (int &i: arr) maxx = max(maxx, i);
        return maxx;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.largest(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends