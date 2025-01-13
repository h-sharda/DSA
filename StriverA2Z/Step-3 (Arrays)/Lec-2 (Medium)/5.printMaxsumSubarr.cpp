// GFG: Maximum Score from Subarray Minimums (Medium)
// link:https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size(), ans =0;
        for (int i =1; i < n; i++) {
            ans = max(ans, arr[i-1]+arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends