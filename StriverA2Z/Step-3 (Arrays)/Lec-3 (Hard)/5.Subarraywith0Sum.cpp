// GFG: Largest subarray with 0 sum (Medium)
// link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int sum = 0, n = arr.size(), ans =0;
        unordered_map <int, int> umap;
        
        for (int i =0; i<n; i++){
            sum += arr[i];
            
            if ( sum == 0) ans = max(ans, i + 1);
            
            if (umap.find(sum) == umap.end()) umap[sum] = i;
            else  ans = max(ans, i-umap[sum]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends