// GFG: Count Digits (Easy)
// link: https://www.geeksforgeeks.org/problems/count-digits5716/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        int ans = 0;
        int temp = n;
        
        while (temp != 0) {
            if (temp % 10 != 0 && n % (temp % 10) == 0) ans++;
            temp /= 10;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends