// Leetcode: 493. Reverse Pairs (Hard)
// link: https://leetcode.com/problems/reverse-pairs/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:

    void merge(vector<int> &nums, int &ans, int start, int mid, int end) {
        int i = start, j = mid +1;

        while (i <= mid && j <= end) {
            if (nums[i] <= 2LL*nums[j] ) i++;
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

    int reversePairs(vector<int>& nums) {
        int ans = 0;
        recurse(nums, ans, 0, nums.size()-1);
        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution s;
        cout << s.reversePairs(nums) << endl;
    }
    return 0;
}