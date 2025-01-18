// GFG : Array Search (Basic)
// link: https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int search(vector<int>& arr, int x) {
        for (int i = 0; i < arr.size(); i++) if (arr[i] == x) return i;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int testcases;
    cin >> testcases;
    cin.ignore(); // To ignore the newline character after reading testcases
    while (testcases--) {
        vector<int> arr;
        int x;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, input); // Read the next line for x
        stringstream ss2(input);
        ss2 >> x;

        Solution ob;
        cout << ob.search(arr, x) << endl; // Linear search
        cout << '~' << endl;
    }

    return 0;
}
// } Driver Code Ends