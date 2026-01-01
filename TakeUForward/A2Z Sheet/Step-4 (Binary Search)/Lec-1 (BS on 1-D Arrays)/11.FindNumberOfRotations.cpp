// GFG: Find Kth Rotation
// link: https://practice.geeksforgeeks.org/problems/rotation4723/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size(), low = 0, high = n-1;

        while ( low <= high ) {
            int mid = (low + high) / 2;
            if (mid < n-1 && nums[mid] > nums[mid+1]) return mid+1;
            
            if (nums[mid] >= nums[low]) low = mid +1;    
            else high = mid - 1;
        }

        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends