// GFG: Frequencies of Limited Range Array Elements (Easy)
// link: https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 0; i<n; i++) {
            if (arr[i] <= 0) continue;
            
            while (arr[i] > 0 ) {
                int pos = arr[i] -1;
                if (arr[pos] <= 0) {
                    arr[pos]--;
                    arr[i] = 0;
                } else {
                    arr[i] = arr[pos];
                    arr[pos] = -1;
                }
            }
        }
        
        for (int i = 0; i<n; i++) {
            arr[i] = -arr[i];
        }
        
        return arr;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.frequencyCount(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no duplicates are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl; // Ensure new line after each test case output
    }

    return 0;
}
// } Driver Code Ends