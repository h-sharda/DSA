//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        k--;
        int m = a.size(), n = b.size();
        if ( m > n ) {
            swap ( a, b);
            swap ( m, n);
        }

        int low = 0, high = m;
        int left1, left2, right1, right2;

        while (low <= high) {
            int mid1 = (low + high)/2;
            int mid2 = k - mid1;
            
            if (mid2 > n) {
                low++;
                continue;
            }

            left1 = mid1 > 0 ? a[mid1 - 1] : INT_MIN;
            right1 = mid1 < m ? a[mid1] : INT_MAX;
            left2 = mid2 > 0 ? b[mid2 - 1] : INT_MIN;
            right2 = mid2 < n ? b[mid2] : INT_MAX;

            if ( left1 <= right2 && left2 <= right1 ) break;
            else if ( left1 > right2 ) high = mid1 - 1;
            else low = mid1 + 1;
        }

        return min ( right1, right2);
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends