// GFG: Longest Sub-Array with Sum K (Medium)
// link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        unordered_map<long long, int> umap;
        umap[0] = -1;
        
        long long sum = 0;
        int n = arr.size(), ans = 0;
        
        for (int i =0; i < n; i++) {
            sum += arr[i];
            long long cmp = sum-k;
            if (umap.find(cmp) != umap.end()) ans = max(ans, i-umap[cmp]);
            if (umap.find(sum) == umap.end()) umap[sum] = i;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
