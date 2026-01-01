// GFG: Count Inversions (Medium)
// link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    void merge(vector<int> &nums, int &ans, int start, int mid, int end) {
        int i = start, j = mid +1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j] ) i++;
            else {
                ans += mid - i + 1;
                j++;
            }
        }

        sort(nums.begin() + start, nums.begin() + end + 1);
    }

    void recurse(vector<int> &nums, int &ans, int start, int end) {
        if (start == end) return;

        int mid = (start + end) / 2;
        recurse(nums, ans, start, mid);
        recurse(nums, ans, mid + 1, end);

        merge (nums, ans, start, mid, end);
    }
    
    int inversionCount(vector<int> &arr) {
        int ans = 0;
        recurse(arr, ans, 0, arr.size()-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends