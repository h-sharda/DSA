// GFG: Missing and Repeating (Easy)
// link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size(), a = 0, a2 = 0;
        long long s = (n * n + n) / 2, s2 = ((2 * n + 1) * (n + 1) * (n)) / 6;
        
        for (int i =0; i < n; i++) {
            a += arr[i];
            a2 += 1LL * arr[i] * arr[i];
        }
        
        int x = (s - a + (s2 - a2) / (s - a)) / 2, y = x - s + a;
        return {y, x};
        
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
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends