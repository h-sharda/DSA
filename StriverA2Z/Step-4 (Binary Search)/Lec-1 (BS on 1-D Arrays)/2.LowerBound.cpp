// GFG: Floor in a Sorted Array (Easy)
// link: https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        
        int low = 0, high = arr.size();
    
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (arr[mid] <= k) low = mid + 1;
            else high = mid -1;
        }
    
        return high;
    
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends