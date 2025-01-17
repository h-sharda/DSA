// GFG: Number of occurrence (Easy)
// link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        int first = -1, last = -1, low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) first = mid;
            if (nums[mid] < target) low = mid + 1;
            else high = mid -1;
        }

        low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) last = mid;
            if (nums[mid] <= target) low = mid + 1;
            else high = mid -1;
        }
    
        return first == -1 ? 0 : last - first + 1;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends