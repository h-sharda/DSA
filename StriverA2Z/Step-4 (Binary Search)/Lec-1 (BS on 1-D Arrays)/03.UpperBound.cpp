// GFG: Ceil The Floor (Easy)
// link: https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int ceilll = -1, flooor = -1;
        
        for (int i =0; i< arr.size(); i++){
            if ( arr[i] <= x && arr[i] > flooor) flooor = arr[i];
            if ( arr[i] >= x && (ceilll == -1 || arr[i] < ceilll) ) ceilll = arr[i];
        }
        
        return {flooor, ceilll};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends