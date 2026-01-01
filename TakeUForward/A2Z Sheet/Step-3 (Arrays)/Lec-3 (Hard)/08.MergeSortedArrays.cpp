// Leetcode: 88. Merge Sorted Array (Easy)
// Link: https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = n + m -1, i = m-1, j = n-1;

        while (pos >= 0) {
            if ( i == -1) nums1[pos--] = nums2[j--];
            else if (j == -1) nums1[pos--] = nums1[i--];
            else if (nums1[i] > nums2[j] ) nums1[pos--] = nums1[i--];
            else nums1[pos--] = nums2[j--];
        }
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<int> nums1(m+n), nums2(n);
        for (int i = 0; i < m; i++) {
            cin >> nums1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> nums2[i];
        }
        Solution s;
        s.merge(nums1, m, nums2, n);
        for (int i = 0; i < m+n; i++) {
            cout << nums1[i] << " ";
        }
        cout << endl;        
    }
    
    return 0;
}