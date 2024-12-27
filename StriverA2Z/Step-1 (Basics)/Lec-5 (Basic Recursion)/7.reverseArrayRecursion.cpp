// GFG: Reverse an Array (Easy)
// link: https://www.geeksforgeeks.org/problems/reverse-an-array/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    void rev(vector<int> &arr, int n, int pos) {
        if (pos == n/2) return;
        swap(arr[pos], arr[n-pos-1]);
        rev(arr, n, pos+1);
    }
    
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        rev(arr, n, 0);
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
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends